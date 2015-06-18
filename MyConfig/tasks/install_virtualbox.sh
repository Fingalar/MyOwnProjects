sudo sh -c 'echo "deb http://download.virtualbox.org/virtualbox/debian wheezy contrib" >> /etc/apt/sources.list'

wget http://download.virtualbox.org/virtualbox/debian/oracle_vbox.asc -O- | sudo apt-key add -

sudo apt-get update

sudo apt-get install virtualbox-4.3

sudo apt-get install virtualbox-dkms
