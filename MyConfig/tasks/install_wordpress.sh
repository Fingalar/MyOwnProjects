mkdir /var/www/wordpress
cd /var/www/wordpress

wget http://wordpress.org/latest.tar.gz
tar xfz latest.tar.gz
mv wordpress/* ./

rmdir ./wordpress/
rm -f latest.tar.gz

#"
#create database dbname;
#grant usage on *.* to username@localhost identified by 'password';
#grant all privileges on dbname.* to username@localhost;
#"
