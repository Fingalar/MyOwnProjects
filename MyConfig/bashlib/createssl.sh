#!/bin/bash

# Create a SSL certificate

if [ $# != 0 ]

	then for i
	do

		openssl genrsa -out $i.key 1024
		openssl req -new -key $i.key -out $i.csr
		openssl x509 -req -days 365 -in $i.csr -signkey $i.key -out $i.crt

		mv $i.crt /etc/ssl/certs
		mv $i.key /etc/ssl/private

		echo "---- Correctly created $i.key ! ----"
	done

	else echo "error: arguments must be valid name"

fi

