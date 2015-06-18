#!/bin/bash

#Connaître l'adresse IP de la machine
ifconfig eth0 | grep "inet adr" | sed 's/.*adr:\([0-9]*\.[0-9]*\.[0-9]*\.[0-9]*\).*/\1/'

#adresse que l'on peut mettre dans une variable IP_machine afin de l'exploiter dans un script :
#IP_machine=`ifconfig eth0 | grep "inet adr" | sed 's/.*adr:\([0-9]*\.[0-9]*\.[0-9]*\.[0-9]*\).*/\1/'`
