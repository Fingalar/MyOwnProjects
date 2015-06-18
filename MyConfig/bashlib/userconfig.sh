#!/n/bash

if [ $# == 1 ]

	then

		printf "\n[Group config]...\n"

		groupadd wheel
		useradd $1
		useradd $1 wheel
		mkhomedir_helper $1

		printf "\n[Password for $1]...\n"

		passwd $1
		cp ../config/.bashrc /home/$1/
		cp ../config/.vimrc /home/$1/
		cp -rf ../config/.vim /home/$1/
		source /home/$1/.bashrc


	else echo "error: invalid name argument"

fi
