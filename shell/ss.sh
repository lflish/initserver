#安装梯子
yum -y install python-setuptools && easy_install pip
pip install shadowsocks

echo "/usr/bin/python /usr/bin/ssserver -s ::0 -p 8086 -k \"passwd\" -m aes-256-cfb --user nobody --workers 5 -d start" > ~/ss.sh

#加入防火墙
iptables -A IN_public_allow -p tcp -m tcp --dport 8086 -m conntrack --ctstate NEW -j ACCEPT

exit 0;
#linux客户端使用
sslocal -c /etc/ss.json
