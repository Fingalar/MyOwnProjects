#!/bin/bash
apt-get install curl build-essential libcap-dev xz-utils zip unzip imagemagick strace curl clang-3.4

curl https://install.meteor.com/ | sh

mkdir /var/www/
git clone https://github.com/sandstorm-io/sandstorm.git /var/www/sandstorm
cd /var/www/sandstorm

make

make install
