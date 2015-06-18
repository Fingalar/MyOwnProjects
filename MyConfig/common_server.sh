#!/n/bash

	printf '\n[Upgrading and installing base dependencies]\n'

	apt-get update
	apt-get upgrade
	apt-get install curl sudo htop python build-essential libssl-dev git-core mongo unzip default-jdk

	 sh tasks/install_lamp.sh
	 sh tasks/install_node.sh
	 sh tasks/git_config.sh
	 sh tasks/www_config.sh	

	printf '\n[Base dependencies done]\n'
