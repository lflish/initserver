python /shadowsocksr/shadowsocks/server.py -s ::0 -o tls1.2_ticket_auth_compatible -p 443 -k "passwd" -m aes-256-cfb --user nobody --workers 2 -d start
