#!/bin/bash

#Savoir si la machine a un processeur 64 bits ou 32 bits
( grep flags /proc/cpuinfo | grep -q '\<lm\>' ) &&  echo 64 bits || echo 32 bits
