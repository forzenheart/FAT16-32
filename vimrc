" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
syntax on

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
"set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"if has("autocmd")
"  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
"endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
"if has("autocmd")
"  filetype plugin indent on
"endif

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
set showcmd		" Show (partial) command in status line.
"set showmatch		" Show matching brackets.
"set ignorecase		" Do case insensitive matching
"set smartcase		" Do smart case matching
"set incsearch		" Incremental search
"set autowrite		" Automatically save before commands like :next and :make
"set hidden		" Hide buffers when they are abandoned
"set mouse=a		" Enable mouse usage (all modes)

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
	source /etc/vim/vimrc.local
endif

filetype plugin on
set history=1000
set nocompatible
set vb t_vb=
set ruler
set noai
set autoindent
set smartindent
set cindent
set nu
set tabstop=8
set softtabstop=8
set shiftwidth=8
set shortmess=atI

set nobackup
set noswapfile

"NERD_commenter
let mapleader = ";"

"auto open NERDTree"
autocmd vimenter * NERDTree
"auto close
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
wincmd w
autocmd VimEnter * wincmd w
"let NERDTreeMinimalUI=1

"taglist
let Tlist_Auto_Open=0
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1 
let Tlist_Ctags_Cmd="/usr/bin/ctags"
let Tlist_File_Fold_Auto_Close=1
let Tlist_Show_Menu=1
""auto open WinManager
let g:NERDTree_title='NERD Tree'
let g:winManagerWindowLayout="TagList|NERDTree"
let g:AutoOpenWinManager = 1
let g:winManagerWidth = 25

"omniCppComplete
set tags+=~/.ctags/cpp_src/cpp
set tags+=~/.ctags/windows
"set tags+=~/.ctags/QT5tags
"set tags+=~/.ctags/QTbaseincludeTags
"set tags+=~/.ctags/QTbaseSrcTags
let OmniCpp_NamespaceSearch = 1
let OmniCpp_GlobalScopeSearch = 1
let OmniCpp_ShowAccess = 1 
let OmniCpp_ShowPrototypeInAbbr = 1
let OmniCpp_DisplayMode = 1
let OmniCpp_MayCompleteDot = 0 
let OmniCpp_MayCompleteArrow = 0 
let OmniCpp_MayCompleteScope = 0 
let OmniCpp_DefaultNamespaces = ["std", "_GLIBCXX_STD"]
""auto close complete window
au CursorMovedI, InsertLeave * if pumvisible() == 0|silent! pclose|endif 
set completeopt=menuone,menu,longest
"highlight Pmenu    guibg=darkgrey  guifg=black 
"highlight PmenuSel guibg=lightgrey guifg=black
""superTab
"let g:SuperTabDefaultCompletionType = "<c-x><c-u>"

"powerline"
"let g:Powerline_symbols = 'fancy'
set laststatus=2
set t_Co=256
let g:Powerline_symbols = 'unicode'
set encoding=utf8

noremap <Up> <Nop>
noremap <Down> <Nop>
noremap <Left> <Nop>
noremap <Right> <Nop>
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
"inoremap < <><ESC>i
inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap { {<CR>}<ESC>O
inoremap , ,<Space>
"inoremap if if<Space>()<Space><ESC>hi
"inoremap while while<Space>()<Space><ESC>hi
"inoremap else if else if<Space>()<Space><ESC>hi
"inoremap switch switch<Space>()<Space><ESC>hi

filetype plugin indent on
"vim在注释下面会自动添加注释标签
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o

set nocompatible              " be iMproved,  required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively,  pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle,  required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
Plugin 'L9'
" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup',  {'rtp': 'vim/'}
" Avoid a name conflict with L9
"Plugin 'user/L9',  {'name': 'newL9'}

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes,  instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line""""""""""""")"''''
Bundle 'https://github.com/Lokaltog/vim-powerline.git'
Bundle 'taglist.vim'
Bundle 'winmanager'
Bundle  'bufexplorer.zip'
Bundle 'OmniCppComplete'
"Bundle 'superTab'
"Bundle 'https://github.com/Shougo/neocomplete.vim.git'

