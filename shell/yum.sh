yum -y install vim gcc net-tools git lrzsz unzip wget

#安装梯子
yum -y install python-setuptools && easy_install pip
pip install shadowsocks

#linux客户端使用
sslocal -c /etc/ss.json
