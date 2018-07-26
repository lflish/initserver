#!/bin/bash
#初始化脚本
sh shell/yum.sh

mv shell/ss.sh ~/

#加入防火墙
iptables -A IN_public_allow -p tcp -m tcp --dport 8086 -m conntrack --ctstate NEW -j ACCEPT

mkdir ~/download 

#初始化脚本
sh shell/hexo.sh
