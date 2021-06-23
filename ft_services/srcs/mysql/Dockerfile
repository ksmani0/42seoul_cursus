FROM alpine:3.12.3

#Mariadb 설치 시 mysql 데이터베이스를 위한 저장 공간 'mysql'이 기본 생성된다
RUN apk add openrc
RUN apk add mariadb mariadb-common mariadb-client
RUN rc-update add mariadb default
RUN rc-status && touch /run/openrc/softlevel

RUN echo "http://nl.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk add influxdb telegraf
RUN mkdir /etc/telegraf
ADD telegraf.conf /etc/telegraf/telegraf.conf
#당연히 각 Dockerfile에서 설치하는 telegraf.conf의 내용은 같다

#ADD: 단순히 파일을 호스트에서 컨테이너로 복사하는 것 외의 기능이 있음
#복사할 대상 자리에 url을 넣으면 다운로드 후 컨테이너에 추가. 특정 압축파일이면 해제해서 전달 
ADD script.sh ./script.sh
ADD wordpress.sql ./wordpress.sql
#ft_server 과제의 이미지로 뽑아낸 wordpress.sql이라 파일 속 ip 주소값을 바꿔줘야 함

#mysql은 기본 설정으로 127.0.0.1 주소의 3306 포트로 접속하게 돼있다
EXPOSE 3306

CMD sh script.sh