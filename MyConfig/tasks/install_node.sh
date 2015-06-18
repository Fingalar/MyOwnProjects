 printf "\n[Install Node via nvm]...\n"
	sudo apt-get install curl build-essential openssl libssl-dev git python
	cd ~/
	git clone git://github.com/creationix/nvm.git ~/.nvm
	printf "\n\n# NVM\nif [ -s ~/.nvm/nvm.sh ]; then\n\tNVM_DIR=~/.nvm\n\tsource ~/.nvm/nvm.sh\nfi" >> ~/.bashrc
	NVM_DIR=~/.nvm
	source ~/.nvm/nvm.sh
	source ~/.bashrc

	nvm install v0.12.2
	nvm alias default v0.12.2
	nvm use v0.12.2

#npm install -g grunt-cli
#npm install -g bower
#npm install -g gulp
#npm install -g mongodb
#npm install -g mongoose

