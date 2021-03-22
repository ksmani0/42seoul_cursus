# docker build -t ft_server .
# Run the docker file from the current location and
# create an image with the name ft_server

FROM debian:buster
# Specifying the image to be used as the basis when creating a new container

LABEL maintainer="seungmki@student.42seoul.kr"
# Write image details such as image version information, author, and comment
# docker image inspect --format="{{ .Config.Lables }}" IMAGENAME
# This part has no effect on the build

# Install the operating system to the latest version
RUN apt-get update && apt-get -y install \
	nginx \
	openssl \
	vim \
	php7.3-fpm \
	mariadb-server \
	php-mysql \
	php-mbstring \
	wget
# Web server program, security protocol, nginx-php linkage module,
# web db server program, php-web db linkage module,
# multi-byte string function support program installed

COPY ./srcs/default ./
COPY ./srcs/ft_server_run.sh ./
COPY ./srcs/db.sql ./
COPY ./srcs/wp-config.php ./
COPY ./srcs/config.inc.php ./
# Deliver files containing detailed environment settings
# Saved detailed command line

EXPOSE 80 443
# Container port number setting

CMD bash ft_server_run.sh
# Run the program to prevent the server from shutting down
