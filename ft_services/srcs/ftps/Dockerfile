FROM alpine:3.12.3

RUN apk update && apk add openrc && apk add vsftpd
RUN rc-status && touch /run/openrc/softlevel 
RUN rc-update add vsftpd default

RUN echo "http://nl.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk add telegraf
RUN mkdir /etc/telegraf
ADD telegraf.conf /etc/telegraf/telegraf.conf

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf

#사용자 계정을 추가하는 adduser 명령어는 useradd 명령어와 심볼링 링크돼있다
#adduser(useradd) 사용자명은 사용자명을 신규 사용자로 추가한다는 것
RUN echo -e "1234\n1234" | adduser testuser

#명령어 tee는 화면에 출력된 내용을 파일로 저장하는데 사용된다.
#testuser를 vsftpd.userlist에 추가한다.
RUN echo "testuser" | tee -a /etc/vsftpd.userlist

RUN apk add openssl
RUN openssl req -x509 -nodes -days 365 -subj \
    "/C=KR/ST=Seoul/L=Gaepodong/O=42Seoul/OU=2nd_term_Gam/CN=127.0.0.1" -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.pem -out /etc/ssl/private/vsftpd.pem

COPY script.sh /script.sh
RUN chmod +x /script.sh

#21번 포트는 FTP의 연결을 제어하는 command 포트
EXPOSE 21

CMD sh script.sh
