# Basics

 export LS_OPTIONS='--color=auto'
 eval "`dircolors`"

 alias ls='ls $LS_OPTIONS'
 alias l='ls $LS_OPTIONS -l'
 alias ll='ls $LS_OPTIONS -lA'
 alias rm='rm -i'

# Git 

 alias gstatus='git status'
 alias gadd='git add -A'
 alias gpush='git push'
 alias gcommit='git commit -m'

# BashLib

 # Detection

  alias ownip='sh ~/.bashlib/ownip.sh'
  alias whichkernel='sh ~/.bashlib/kernel.sh'
  alias whichdistrib='sh ~/.bashlib/distrib.sh'
  alias grouplist='sh ~/.bashlib/groupl.sh'
  alias publicip='sh ~/.bashlib/publicip.sh'
  alias whicharchi='sh ~/.bashlib/whicharchi.sh'
  alias biggestfiles='sh ~/.bashlib/biggestfiles.sh'
  alias usergroups='sh ~/.bashlib/usergroups.sh'
  alias createssl='sh ~/.bashlib/createssl.sh'

