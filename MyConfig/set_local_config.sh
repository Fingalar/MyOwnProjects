#!/bin/bash

	cp config/.bashrc ~/
	cp config/.vimrc ~/
	cp -rf config/.vim ~/


	mkdir ~/.bashlib
	cp -Rf bashlib/* ~/.bashlib/
	cp -Rf config ~/.bashlib/
	. ~/.bashrc
	
	printf '\n[Config done]\n'
