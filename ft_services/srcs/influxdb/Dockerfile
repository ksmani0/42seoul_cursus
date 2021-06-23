FROM alpine:3.12.3

RUN apk update && apk add openrc
RUN rc-status && touch /run/openrc/softlevel 

RUN echo "http://nl.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk add influxdb telegraf
RUN mkdir /etc/telegraf
ADD telegraf.conf /etc/telegraf/telegraf.conf

COPY script.sh /script.sh
RUN chmod +x /script.sh

EXPOSE 8086

CMD [ "sh", "script.sh" ]



