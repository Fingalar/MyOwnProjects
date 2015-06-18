" == Common settings ==
set nocompatible		" Disable vi compatibility
set title				" Display filename in title bar
set number				" Show line number
set ruler				" Show cursor position
set showcmd				" Show incomplete command
syntax on				" Syntax coloration

" == Cursor ==
set mouse=a				" Enable mouse support
set cursorline			" Show cursorline
"set nowrap				" Don't wrap text on multiple lines
set scrolloff=7			" Display minimum X lines around the cursor
"set sidescrolloff=5		" Display minimum X columns around the cursor

" == Indentation ==
set noexpandtab			" Disable tab to spaces
set autoindent			" Same indent as previous lines
set smartindent			" Auto-indentation in while, if, etc...
set tabstop=4			" 4 column by tab
set shiftwidth=4		" Auto-indent with 4 columns
set softtabstop=4		" 4 column by tab

" == Vim menu ==
set wildmenu			" Enhance vim menu completion
set wildignore+=*/tmp/*,*.so,*.swp,*.a,a.out,*.o,*~,*.pyc

" == Search ==
set history=500			" 500 command line history
set ignorecase			" Ignore case in search
set smartcase			" Don't ignore case when capitale is typed
set incsearch			" Highlight typed word during typing
set hlsearch			" Highlight typed word

" == Theme ==
"colorscheme desert		" Enable desert theme
colorscheme mustang		" Enable mustang theme
"highlight Normal ctermfg=white
highlight LineNr ctermbg=234 ctermfg=239
"highlight CursorLine term=underline cterm=None ctermbg=234

" == Auto .h protect ==
function! s:insert_gates()
let getname = substitute(toupper(expand("%:t")), "\\.", "_", "g")
	execute "normal! i#ifndef " . getname
	execute "normal! o# define " . getname
	execute "normal! o"
	execute "normal! Go#endif /* !" . getname . " */"
	normal! kk
endfunction
autocmd BufNewFile *.{h,hpp} call <SID>insert_gates()
autocmd BufNewFile *.{h,hpp} :3

" == Mapping ==
nmap <c-x> :w<cr>
nmap <c-c> :q<cr>
nmap <c-e> :Exp<cr>
nmap <c-b> :CtrlPBuffer<cr>

let mapleader="\\"
"nmap <silent> <leader>ev :edit $HOME/.vimrc<CR>		" Edit vimrc
"nmap <silent> <leader>sv :source $HOME/.vimrc<CR>		" Source vimrc
nmap <silent> <leader>ev :edit $HOME/.myvimrc<CR>		" Edit myvimrc
nmap <silent> <leader>sv :source $HOME/.myvimrc<CR>	" Source myvimrc


" == Misc ==
"set showmatch			" Show matching bracket
"set matchtime=10		" Show matching bracket for 1 second

" == Norme C 42==
highlight normec42 ctermbg=red ctermfg=white guibg=#592929
autocmd BufEnter *.{c,cpp,h,hpp} call matchadd ('normec42', '^ ')				"espace au debut
autocmd BufEnter *.{c,cpp,h,hpp} call matchadd ('normec42', '  \+')				"double espace
autocmd BufEnter *.{c,cpp,h,hpp} call matchadd ('normec42', ' \t')				"espace suivit de tab
autocmd BufEnter *.{c,cpp,h,hpp} call matchadd ('normec42', '\t ')				"tab suivit d'espace
autocmd BufEnter *.{c,cpp,h,hpp} call matchadd ('normec42', '[ \t]\+$')			"tab ou espace a la fin
autocmd BufEnter *.{c,cpp,h,hpp} call matchadd ('normec42', '\%>80v.\+')		"plus de 80 caracteres
"autocmd BufEnter *.{c,cpp,h,hpp} call matchadd ('normec42', ',[^ ]')			"virgule sans espace

" == Backups ==
"if isdirectory($HOME . '/.vim/backup') == 0
"	:silent !mkdir -p ~/.vim/backup >/dev/null 2>&1
"endif
"set backupdir-=.
"set backupdir+=.
"set backupdir-=~/
"set backupdir^=~/.vim/backup/
"set backup

" == Swap files ==
"if isdirectory($HOME . '/.vim/swap') == 0
"	:silent !mkdir -p ~/.vim/swap >/dev/null 2>&1
"endif
"set directory=~/.vim/swap//
"set directory+=.
