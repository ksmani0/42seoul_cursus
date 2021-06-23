#!/bin/sh

#Strating telegraf and nginx
telegraf & rc-service nginx start

rc-service php-fpm7 start

sleep 2
while true;
do
    if ! pgrep nginx; then
        echo "nginx is not running!"
        exit 1
    fi
    if ! pgrep php-fpm7; then
        echo "php-fpm7 is not running!"
        exit 1
    fi
    if ! pgrep telegraf; then
        echo "telegraf is not running!"
        exit 1
    fi
    sleep 2
done

exit 0