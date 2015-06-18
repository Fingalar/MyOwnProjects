apt-get install mysql-server php5 php5-cli php5-mysql php5-gd php5-mcrypt php5-memcache unzip

cd /root/
wget http://www.prestashop.com/download/old/prestashop_1.6.0.9.zip
unzip prestashop_1.6.0.9.zip

echo "
mysql> CREATE DATABASE prestashopdb;
mysql> GRANT ALL PRIVILEGES ON prestashopdb.* TO 'prestashop'@'localhost' IDENTIFIED BY 'your-password' WITH GRANT OPTION;
mysql> FLUSH PRIVILEGES;
mysql> quit
"

mysql -u root -p

touch /etc/apache2/sites-available/prestashop.conf
echo "
<VirtualHost *:80>
ServerAdmin admin@your-domain.com
DocumentRoot /var/www/prestashop/
ServerName your-domain.com
ServerAlias www.your-domain.com
<Directory /var/www/prestashop/>
Options FollowSymLinks Indexes MultiViews
AllowOverride All
</Directory>
ErrorLog /var/log/apache2/your-domain.com-error_log
CustomLog /var/log/apache2/your-domain.com-access_log common
</VirtualHost>
" >> /etc/apache2/sites-available/prestashop.conf

ln -s /etc/apache2/sites-available/prestashop.conf /etc/apache2/sites-enabled/prestashop.conf

mv /root/prestashop/ /var/www/prestashop/

chown www-data:www-data -R /var/www/prestashop/


