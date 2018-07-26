#!/bin/bash

#安装hexo
curl --silent --location https://rpm.nodesource.com/setup_8.x | sudo bash -

sudo yum -y install nodejs

npm i -g hexo

exit 0

#安装hexo
wget https://nodejs.org/dist/v8.11.3/node-v8.11.3-linux-x64.tar.xz -P ~/download

xz -d node-v8.11.3-linux-x64.tar.xz
tar xvf node-v8.11.3-linux-x64.tar


