git config --global user.email "hxy.gold@gmail.com"
git config --global user.name "lflish"

#记录密码
git config --global credential.helper store

#生成公钥
ssh-keygen -t ed25519 -C "hxy.gold@gmail.com"

#vertify pubkey
#ssh -T git@github.com

#~/.ssh/config
value="Host github.com
    HostName ssh.github.com
    User git
    Port 443
"
