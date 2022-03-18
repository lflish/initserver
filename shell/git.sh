git config --global user.email "hxy.gold@gmail.com"
git config --global user.name "lflish"

#记录密码
git config --global credential.helper store

#生成公钥
ssh-keygen -t ed25519 -C "hxy.gold@gmail.com"

