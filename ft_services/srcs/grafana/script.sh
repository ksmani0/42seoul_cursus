#!/bin/sh

#Strating telegraf and grafana
telegraf &>/dev/null &

#The grafana-server binary .tar.gz는 바이너리와 공용 폴더가 있는 루트 설치 디렉토리가 될 작업 디렉토리가 필요하다.
( ./grafana/bin/grafana-server -homepath ./grafana 1>/dev/null) &

sleep 3
while true;
do
	if ! pgrep telegraf 1>/dev/null; then
		echo "telegraf is not running!"
		exit 1
	else
		echo "telegraf is running!"
	fi
	if ! pgrep grafana-server 1>/dev/null; then
		echo "grafana Service is not running!"
		exit 1
	else
		echo "grafana Service is running!"
	fi
	sleep 2
done

exit 0
