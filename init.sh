#!/bin/bash

mkdir ~/download 

function init()
{
	echo "init $1"

	cd $1
	sh ./init.sh 
	cd ..
}

#基本软件安装
init shell 

#工具环境初始化
init tools

exit 0
