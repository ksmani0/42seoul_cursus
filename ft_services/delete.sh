#!/bin/sh
kubectl delete deployment --all
kubectl delete service --all
kubectl delete pod --all

docker stop $(docker ps -aq)
docker rm $(docker ps -aq)
docker rmi $(docker images -q)


####################
#kubectl delete deployment --all
#kubectl delete service --all
#kubectl delete pod --all

#docker stop $(docker ps -aq)
#docker rm $(docker ps -aq)
#docker rmi $(docker images -q)

#kubectl delete -f srcs/ftps/ftps.yaml
#kubectl delete -f srcs/telegraf/telegraf.yaml
#kubectl delete -f srcs/grafana/grafana.yaml
#kubectl delete -f srcs/influx/influx.yaml
#kubectl delete -f srcs/mysql/mysql.yaml
#kubectl delete -f srcs/wordpress/wordpress.yaml
#kubectl delete -f srcs/phpmyadmin/phpmyadmin.yaml
#kubectl delete -f srcs/nginx/nginx.yaml
#kubectl delete -f srcs/metallb.yaml

#minikube delete

#kubectl delete svc --all
#kubectl delete rc --all #replication controller
#kubectl delete pod --all
