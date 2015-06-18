

useradd ts3
mkdir /home/ts3
chown -R ts3: /home/ts3

su ts3
cd /home/ts3


wget http://ftp.4players.de/pub/hosted/ts3/releases/3.0.7/teamspeak3-server_linux-amd64-3.0.7.tar.gz

tar -zxvf teamspeak3-server_linux-amd64-3.0.7.tar.gz

touch /etc/init.d/teamspeak

echo "
#! /bin/sh
### BEGIN INIT INFO
# Provides:          teamspeak
# Required-Start:    networking
# Required-Stop:
# Default-Start:     2 3 4 5
# Default-Stop:      S 0 1 6
# Short-Description: TeamSpeak Server Daemon
# Description:       Starts/Stops/Restarts the TeamSpeak Server Daemon
### END INIT INFO

set -e

PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin
DESC="TeamSpeak Server"
NAME=ts3
USER=ts3
DIR=/home/ts3/teamspeak3-server_linux-amd64
DAEMON=$DIR/ts3server_startscript.sh
#PIDFILE=/var/run/$NAME.pid
SCRIPTNAME=/etc/init.d/$NAME

# Gracefully exit if the package has been removed.
test -x $DAEMON || exit 0
" >> /etc/init.d/teamspeak

chmod 755 /etc/init.d/teamspeak
update-rc.d teamspeak defaults

#cd $DIR
#sudo -u ts3 ./ts3server_startscript.sh $1

#cd teamspeak3-server_linux-amd64
#sh ts3server_startscript.sh start


# AT FIRST START SAVE THE TOKEN
