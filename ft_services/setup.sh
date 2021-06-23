#!/bin/bash -e

BLUE="\033[34m"
CYAN="\033[36m"
YELLOW="\033[93m"
END="\033[0m"

welcome()
{
	echo -e $BLUE
	echo "##################################################################################"
	echo -e $CYAN
	echo " seungmki's                                                                       "
	echo "    FFF               SSSS     EEE    R  RRRR V     V I   CCCCC     EEE     SSSS  "
	echo "   F   F   T         S    S   E   E   R R     V     V    C     C   E   E   S    S "
	echo "   F       T         S       E     E  RR       V   V  I C         E     E  S      "
	echo " FFFFFFF TTTTT        SSSS  EEEEEEEEE R        V   V  I C        EEEEEEEEE  SSSS  "
	echo "   F       T              S  E        R         V V   I C         E             S "
	echo "   F       T         S    S  E      E R         V V   I  C     C  E      E S    S "
	echo "   F        TTT ----  SSSS    EEEEEE  R          V    I   CCCCC    EEEEEE   SSSS  "
	echo -e $BLUE
	echo "##################################################################################${END}"
}

#미니쿠베 시작. 첫 시작 후엔 굳이 실행 안 해도 됨
#minikube start --driver hyperkit
#minikube start --driver=virtualbox

#쉘이 미니쿠베의 docker-daemon와 연결되도록 함
eval $(minikube docker-env)

kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
#미니쿠베 start 때 한 번만 적용됨. 그 이후엔 계속 같은 걸 사용
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

MINI_IP=$(minikube ip)
sed -i "s/MINI_IP/$MINI_IP/g" srcs/metallb.yaml
sed -i "s/MINI_IP/$MINI_IP/g" srcs/mysql/wordpress.sql
sed -i "s/MINI_IP/$MINI_IP/g" srcs/ftps/vsftpd.conf

kubectl apply -f ./srcs/metallb.yaml

docker build -t nginx       ./srcs/nginx >> logs.txt
docker build -t phpmyadmin  ./srcs/phpmyadmin >> logs.txt
docker build -t wordpress   ./srcs/wordpress >> logs.txt
docker build -t mysql       ./srcs/mysql >> logs.txt
docker build -t influxdb    ./srcs/influxdb >> logs.txt
docker build -t grafana     ./srcs/grafana >> logs.txt
docker build -t ftps        ./srcs/ftps >> logs.txt
printf "${YELLOW}...Building images done...\n${END}"

kubectl apply -f ./srcs/nginx/nginx.yaml >> logs.txt
kubectl apply -f ./srcs/mysql/mysql.yaml >> logs.txt
kubectl apply -f ./srcs/wordpress/wordpress.yaml >> logs.txt
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml >> logs.txt
kubectl apply -f ./srcs/influxdb/influxdb.yaml >> logs.txt
kubectl apply -f ./srcs/grafana/grafana.yaml >> logs.txt
kubectl apply -f ./srcs/ftps/ftps.yaml >> logs.txt
printf "${YELLOW}...Deployment done...\n${END}"

welcome
echo "⭐️seungmki's ft_services IP(=minikube IP): $MINI_IP"