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
	struct sockaddr_un cli = {0};
	socklen_t clen = sizeof(cli);
	int fd = 0, ret = 0, size = 0;
	char buf[1024] = {0};
	/* 创建 Unix daemon socket */
	fd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if(fd < 0)
		return; 
	/* 初始化一个unix domain结构体 */
	strncpy(un.sun_path, UNSOCK_SPATH, sizeof(un.sun_path) - 1);
	un.sun_family = AF_UNIX;
	/* 绑定 unix domain 与 套接字 */
	ret = bind(fd, (const struct sockaddr *)&un, sizeof(un));
	if(ret < 0){
		ret = -2;
		goto errout;
	}
	while(1)
	{
		/* 等待接收 */
		size = recvfrom(fd, buf, 1024, 0, (struct sockaddr *)&cli, &clen);
		if(size < 0)
			goto errout;
	
		printf("recv msg = %s\n", buf);
		/* 消息回复 */
		sendto(fd, "I am server", strlen("I am server"), 0, (struct sockaddr *)&cli, clen);
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
	struct sockaddr_un sun = {0};
	char buf[1024] = {0};
	int fd = 0, ret = 0;
	/* 创建socket */
	fd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if(fd < 0)
		return ;
	/* 初始化一个 unix domain结构体 */
	strncpy(un.sun_path, UNSOCK_CPATH, sizeof(un.sun_path) - 1);
	un.sun_family = AF_UNIX;
	/* 绑定 socket与unix domain地址 */
	ret = bind(fd, (struct sockaddr *)&un, sizeof(un));
	if(ret < 0){
		ret = -2;
		goto errout;
	}
	/* 初始化一个unix domain结构体 这个是服务器的地址 */
	sun.sun_family = AF_UNIX;
	strncpy(sun.sun_path,UNSOCK_SPATH, sizeof(sun.sun_path) - 1);
	/* 发送消息 */
	sendto(fd, "I am client", strlen("I am client"), 0, (struct sockaddr *)&sun, sizeof(sun));
	/* 接收消息 */
	recvfrom(fd, buf, 1024, 0, NULL, 0);
	printf("recv = %s\n", buf);
	
	return ;
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