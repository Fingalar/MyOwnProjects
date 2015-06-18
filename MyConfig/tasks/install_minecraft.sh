apt-get install default-jdk screen wget 

mkdir /var/www/
mkdir /var/www/minecraft
cd /var/www/minecraft
wget -O minecraft_server.jar https://s3.amazonaws.com/Minecraft.Download/versions/1.7.4/minecraft_server.1.7.4.jar

echo "java -Xmx1024M -Xms1024M -jar minecraft_server.jar nogui" > startscript.sh
