sudo apt-get install librrds-perl libhttp-daemon-perl libhttp-daemon-ssl-per
l libjson-perl

wget https://github.com/XavierBerger/RPi-Monitor-deb/blob/master/packages/rpimonitor_2.0-1_all.deb?raw=true -O rpimonitor_1.0-1_all.deb

sudo dpkg -i rpimonitor_1.0-1_all.deb

rm -Rf rpimonitor_1.0-1_all.deb
