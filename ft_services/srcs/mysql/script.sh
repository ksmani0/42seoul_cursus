#!/bin/sh

telegraf &

#Mariadb에서 Oracle의 Data Buffer cache 역할을 하는 것이 InnoB Buffer Pool.
#데이터를 읽을 때 Disk I/O 비용에 따른 부하를 줄이기 위해 메모리에 액세스하려는 데이터를 올려놓고 사용하게 된다.
#이 buffer pool은 재가동 뒤에는 초기화 되므로 재가동 직전에 데이터를 액세스하는 작업이 상대적으로 느려질 수 있다.
#이를 방지하고자 InnoDB는 shutdown 직전에 buffer pool를 dump하며 이때 생성되는 파일이 ib_buffer_pool.
#그리고 다시 mariadb가 재가동 되면 이 파일을 읽어 shutdown 전의 buffer pool상태로 복구해주게 된다.
if [ ! -f "/var/lib/mysql/ib_buffer_pool" ]; then
    echo "-------Install-------"
    /etc/init.d/mariadb setup
    rc-service mariadb start
    echo "--------setup--------"
    echo "CREATE DATABASE wordpress;" | mysql -u root
    echo "CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';" | mysql -u root
    echo "grant all privileges on *.* to 'admin'@'%';" | mysql -u root
    echo "flush privileges;" | mysql -u root
    mysql -u root wordpress < wordpress.sql
    echo "-----------done----------"
    rc-service mariadb stop
fi
#Wordpress 데이터베이스를 만든다
#FLUSH PRIVILEGES: 변경 사항을 즉시 반영하도록 허가 테이블을 다시 로드한다

sed -i "s/skip-networking/# skip-networking/g" /etc/my.cnf.d/mariadb-server.cnf
rc-service mariadb start

sleep 2
while true;
do
    if ! pgrep telegraf 1>/dev/null; then
		echo "telegraf is not running !"
		exit 1
	else
		echo "telegraf is running !"
	fi
    if ! pgrep mysql 1>/dev/null; then
	    echo "mariadb is not running !"
	    exit 1
    else
        echo "mariadb is running !"
    fi
    sleep 2
done

exit 0