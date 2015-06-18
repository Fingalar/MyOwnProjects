#!/bin/bash

#chercher les 10 plus gros fichiers dans le répertoire /home
find /home -type f -exec du -s {} \; | sort -n | tail -n 10

#liste des fichiers modifiés depuis moins d'une minute
find ~ -type f -mmin -1

#Supprimer des dossiers en masse en sécurité
find /home -type d -regex '/home/[^/]+/profil/appdata/LibreOffice' -exec echo rm -Rf{} \;> supprime_ooo.bash
