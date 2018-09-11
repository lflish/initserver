#!/bin/bash

#基本工具安装
sh shell/yum.sh

#安装梯子
sh shell/ss.sh

mkdir ~/download 

#博客环境搭建
sh shell/hexo.sh
