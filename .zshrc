PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin:$HOME/.brew/bin
HISTFILE=~/.zshrc_history
SAVEHIST=5000
HISTSIZE=5000

PATH=$HOME/.brew/bin:$PATH
PATH=$HOME/.brew/opt/ruby/bin:$PATH
PATH=$HOME/.brew/opt/nginx/sbin:$PATH
export SECRET_KEY_BASE="key_string_a_generer"
setopt inc_append_history
setopt share_history

alias ruby="~/.brew/bin/ruby"
alias gem="~/.brew/opt/ruby/bin/gem"

if [[ -f ~/.myzshrc ]]; then
  source ~/.myzshrc
fi

USER=`/usr/bin/whoami`
export USER
GROUP=`/usr/bin/id -gn $user`
export GROUP
MAIL="$USER@student.42.fr"
export MAIL
