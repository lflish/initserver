#include <sys/socket.h>
#include <sys/un.h>
#include <error.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#define UNSOCK_SPATH "/tmp/server.sock"
#define UNSOCK_CPATH "/tmp/client.sock"
void server()
{
	unlink(UNSOCK_SPATH);
	struct sockaddr_un un = {0};
	int fd;
	int ret;
	/* 创建 Unix daemon socket */
	fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(fd < 0)
		return; 
	/* 初始化一个unix domain结构体 */
	strncpy(un.sun_path, UNSOCK_SPATH, sizeof(un.sun_path) - 1);
	un.sun_family = AF_UNIX;
	/* 绑定 unix domain 与 套接字 */
	int l = sizeof(struct sockaddr_un);
	//ret = bind(fd, (const struct sockaddr_un*)&un, l);
	ret = bind(fd, (const struct sockaddr *)&un, l);
	if(ret < 0){
		ret = -2;
		goto errout;
	}
	/* 监听socket */
	listen(fd, 3);
	struct sockaddr_un cli;
	socklen_t clen = sizeof(cli);
	int cfd = 0;
	while(1)
	{
		/* 接收client socket */
		//cfd = accept(fd, (struct sockaddr_un*)&cli, &clen);
		cfd = accept(fd, (struct sockaddr* )&cli, &clen);
		if(ret < 0){
			ret = -3;
			goto errout;
		}
		printf("client is from %s\n", cli.sun_path);
		char buf[1024] = {0};
		/* 交互就使用 client的socket了 */
		/* 接收 */
		recv(cfd, buf, 1024, 0);
		printf("recv%s\n", buf);
		/* 发送 */
		send(cfd, "I am server", strlen("I am server"), 0);
	}
errout:
	close(fd);
	printf("error = %d\n", ret);
	return ;
}
void client()
{
	unlink(UNSOCK_CPATH);
	struct sockaddr_un un = {0};
	int fd;
	int ret;
	/* 创建socket */
	fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(fd < 0)
		return ;
	/* 初始化一个 unix domain结构体*/
	strncpy(un.sun_path, UNSOCK_CPATH, sizeof(un.sun_path) - 1);
	un.sun_family = AF_UNIX;
	/* 绑定 socket与unix domain地址 */
	int l = sizeof(struct sockaddr_un);
	//ret = bind(fd, (struct sockaddr_un*)&un, l);
	ret = bind(fd, (struct sockaddr *)&un, l);
	if(ret < 0){
		ret = -2;
		goto errout;
	}
	/* 初始化一个unix domain结构体 这个是服务器的地址 */
	struct sockaddr_un sun = {0};
	sun.sun_family = AF_UNIX;
	strncpy(sun.sun_path,UNSOCK_SPATH, sizeof(sun.sun_path) - 1);
	/* 连接服务器 */
	connect(fd, (struct sockaddr *)&sun, sizeof(struct sockaddr_un));
	/* 交互部分，这里使用自己的socket */
	send(fd, "I am client", strlen("I am client"), 0);
	char buf[1024] = {0};
	recv(fd, buf, 1024, 0);
	printf("recv%s\n", buf);
errout:
	close(fd);
	printf("error = %d\n", ret);
	return ;
}
int main(int argc ,char **argv)
{
	if(!strcmp(argv[1], "server"))
		server();
	else if(!strcmp(argv[1], "client"))
		client();
	else
		printf("error\n");
	return 0;
}
