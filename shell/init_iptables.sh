#设置默认策略,所有包丢弃
iptables -P INPUT DROP 
iptables -P OUTPUT ACCEPT 
#iptables -P FORWALLD ACCEPT

#sleep 60
#设置sshd端口放行
iptables -A INPUT -p tcp --dport 22 -j ACCEPT
#设置shadowsocks端口放行
iptables -A INPUT -p tcp --dport 8080 -j ACCEPT
#设置shadowsocksR端口放行
iptables -A INPUT -p tcp --dport 443 -j ACCEPT
#设置svn端口放行
#iptables -A INPUT -p tcp --dport 3690 -j ACCEPT
#设置nginx端口放行
iptables -A INPUT -p tcp --dport 80 -j ACCEPT

iptables -A  INPUT -s 192.168.100.100 -j ACCEPT

#允许合法链接并丢弃非法连接
iptables -I INPUT -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT 
iptables -I INPUT -m state --state INVALID -j DROP
