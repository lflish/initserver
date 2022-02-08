# 安装postgreSql
yum install https://download.postgresql.org/pub/repos/yum/reporpms/EL-7-x86_64/pgdg-redhat-repo-latest.noarch.rpm
yum install -y postgresql10-server postgresql10-contrib

# 初始化数据库
/usr/pgsql-10/bin/postgresql-10-setup initdb
