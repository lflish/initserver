#安装梯子
yum -y install python-setuptools && easy_install pip
pip install shadowsocks

#echo "/usr/bin/python /usr/bin/ssserver -s ::0 -p 8086 -k \"passwd\" -m aes-256-cfb --user nobody --workers 5 -d start" > ~/ss.sh
#echo "/usr/bin/python /shadowsocksr/shadowsocks/server.py -s ::0 -o tls1.2_ticket_auth_compatible -p 443 -k "passwd" -m aes-256-cfb --user nobody --workers 2 -d start" > ~/.ssr.sh

#加入防火墙
iptables -A IN_public_allow -p tcp -m tcp --dport 443 -m conntrack --ctstate NEW -j ACCEPT

exit 0;
