#!/bin/bash

# Set permissions
chmod 775 /ft_server_run.sh

# setting permissions for nginx.conf, phpmyadmin
chown -R www-data:www-data /var/www/
chmod -R 755 /var/www/
chmod 705 /config.inc.php

# Generate ssl private key and certificate
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Gaepodong/O=42Seoul/OU=2nd_term_Gam/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

# Apply private key and certificate to my server
mv localhost.dev.crt /etc/ssl/certs/
mv localhost.dev.key /etc/ssl/private/

# Give privileges only to the root account
chmod 600 /etc/ssl/certs/localhost.dev.crt /etc/ssl/private/localhost.dev.key

# nginx setting
cp -rp ./default /etc/nginx/sites-available/

# DB setup and application
service mysql start
mysql < db.sql

# wordpress installation and matching the wordpress user group
# to the user value(www-data) in nginx.conf
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./wp-config.php /var/www/html/wordpress

# phpmyadmin setup
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm phpMyAdmin-5.0.2-all-languages.tar.gz
cp -rp ./config.inc.php /var/www/html/phpmyadmin/

# Start to apply the settings
service nginx start
service php7.3-fpm start

bash
