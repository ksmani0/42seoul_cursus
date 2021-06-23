FROM alpine:3.12.3

RUN apk update && apk add wget libc6-compat openrc
RUN rc-status && touch /run/openrc/softlevel

RUN wget https://dl.grafana.com/oss/release/grafana-7.3.7.linux-amd64.tar.gz 
RUN tar -zxvf grafana-7.3.7.linux-amd64.tar.gz && rm -f grafana-7.3.7.linux-amd64.tar.gz
RUN mv grafana-7.3.7 grafana

RUN echo "http://nl.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk add telegraf
RUN mkdir /etc/telegraf
ADD telegraf.conf /etc/telegraf/telegraf.conf

ADD grafana.db /grafana/data/grafana.db

COPY script.sh /script.sh
RUN chmod +x /script.sh

EXPOSE 3000

CMD [ "sh", "script.sh" ]