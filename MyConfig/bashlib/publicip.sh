#!/bin/bash

#Connaître l'adresse publique du routeur ou du proxy
echo `wget -q -O - http://www.whatismyip.org`
#adresse que l'on peut mettre dans une variable IP_publique afin de l'exploiter dans un script :
#IP_publique=`wget -q -O - http://www.whatismyip.org`
