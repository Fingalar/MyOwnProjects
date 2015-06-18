#!/bin/bash

mkdir /home/wheel/tfrere/Documents

echo "lock file = /var/run/rsync.lock
log file = /var/log/rsyncd.log
pid file = /var/run/rsyncd.pid

[documents]
    path = /home/tfrere/Documents
    comment = The documents folder of Juan
    uid = tfrere
    gid = tfrere
    read only = no
    list = yes
    auth users = rsyncclient
    secrets file = /etc/rsyncd.secrets
    hosts allow = 192.168.1.0/255.255.255.0
" > /etc/rsyncd.conf

echo "
rsyncclient:passWord
juan:PassWord
backup:Password
user:password
" > /etc/rsyncd.secrets

sudo chmod 600 /etc/rsyncd.secrets

sudo rsync --daemon

# sudo kill `cat /var/run/rsyncd.pid`
