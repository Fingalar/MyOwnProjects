echo "deb http://http.debian.net/debian wheezy-backports main" >> /etc/apt/sources.list

sudo apt-get update
sudo apt-get install -t wheezy-backports linux-image-amd64

# REBOOT
