#!/bin/sh

#Strating telegraf and nginx
telegraf & rc-service nginx restart

#Strating service sshd start
rc-service sshd start

#checking status
sleep 2
while true;
do
    if ! pgrep nginx; then
        echo "nginx is not running!"
        exit 1
    fi
    if ! pgrep sshd; then
        echo "sshd service stopped!"
        exit 1
    fi
    if ! pgrep telegraf; then
        echo "telegraf is not running!"
	    exit 1
    fi
    sleep 2
done

exit 0
