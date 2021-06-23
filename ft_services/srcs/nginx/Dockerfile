FROM alpine:3.12.3

#Install nginx and dependencies
#oepnrc: Unix 계열 시스템 같은 운영 체제에서 경로가 알려진 응용 프로그램(여기에선 nginx)이나 문서를 직접 여는 데 사용
RUN apk update && apk add nginx curl openrc
RUN rc-status && touch /run/openrc/softlevel
#/run/openrc/softlevel 없이 openrc를 실행하면 다른 init이 떠 있다고 오류가 발생한다.

#rc-update 도구는 openrc 패키지의 일부
#시스템이 재부팅될 때 nginx가 시작되는지 확인
RUN rc-update add nginx default

#nginx에 대한 새 사용자 및 그룹 'www' 만들기 && html 파일을 위한 디렉토리 만들기
RUN adduser -D -g 'www' www && mkdir /www
RUN chown -R www:www /var/lib/nginx && chown -R www:www /www

#/etc/apk/repositories에 추가 태그가 지정된 저장소를 지정할 수 있다.
RUN echo "http://nl.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk add telegraf && mkdir /etc/telegraf
ADD telegraf.conf /etc/telegraf/telegraf.conf
#telegraf 팟을 별도 구성하는 대신 필요 팟마다 dockerfile을 이용해 설치하는 방식 채택

#내가 작성한 설정 파일 .conf를 ningx에 적용한다 
COPY nginx.conf /etc/nginx/nginx.conf
COPY index.html /www/index.html
#서버의 index.html이 위치한 곳이 시작 지점이자 서버의 root directory다.
#이곳을 기준으로 url을 받아 해당하는 문서를 찾아 클라이언트에게 응답하게 된다.

RUN apk add openssl
RUN openssl req -x509 -nodes -days 365 -subj \
    "/C=KR/ST=Seoul/L=Gaepodong/O=42Seoul/OU=2nd_term_Gam/CN=127.0.0.1" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

RUN apk add openssh && rc-update add sshd default
#ssh 키를 이용한 계정을 생성함
RUN adduser -D testuser
RUN echo "testuser:1234" | chpasswd
RUN ssh-keygen -A
#ssh-keygen -A로 SSH 연결 허용
#시스템에 호스트 키(rsa1, rsa, dsa, ecdsa, ed25519)가 없으면 ssh-keygen -A가 이를 생성

COPY test.html /home/testuser/test.html
#ftps로 파일 업로드, 다운로드할 때 쓸 샘플

COPY script.sh /script.sh
RUN chmod +x /script.sh

EXPOSE 80 443 22
#컨테이너 포트 번호 설정. 포트 22번은 ssh용
#사실 22번은 이미 Mac에서 SSH 포트로 설정돼있긴 하다... 0_0a

#CMD나 ENTRYPOINT는 컨테이너가 시작될 때 스크립트 또는 명령을 실행한다.
CMD ["sh", "script.sh"]
