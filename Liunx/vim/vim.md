![img](vim.assets/vi-vim-cheat-sheet-sch.gif)

- w,e开头和结尾
- d + p：剪切粘贴
- r x :替换为x
- ce：change until end
- cc删整行修改，cw ce c$
- gg到开头G到结尾，Ctrl加g显示状态，行数加G到位置
- /?搜索，n是下一个，N是上一个
- Ctrl o返回上一处,C^i下一处
- %找matching
- :s/old/new/g 将本行的所有old改为new
- type   :#,#s/old/new/g    where #,# are the line numbers of the range
                                 of lines where the substitution is to be done.
       Type   :%s/old/new/g      to change every occurrence in the whole file.
       Type   :%s/old/new/gc     to find every occurrence in the whole file,
                                 with a prompt whether to substitute or not.
- :!执行外部命令
- v进行选中，d+p
- :r 将文件内容插入或者命令回显
- oO上下插行
- R:替换模式
- y+p：y是复制，使用v选择
- :set ic（ignore case）
- /ignore\c
- Typing ":set xxx" sets the option "xxx".  Some options are:
         'ic' 'ignorecase'       ignore upper/lower case when searching
         'is' 'incsearch'        show partial matches for a search phrase
         'hls' 'hlsearch'        highlight all matching phrases
      You can either use the long or the short option name.
  7. Prepend "no" to switch an option off:   :set noic
  7. 补全ctrl d
- **i** -- 切换到输入模式，在光标当前位置开始输入文本。
- **x** -- 删除当前光标所在处的字符。
- **:** -- 切换到底线命令模式，以在最底一行输入命令。
- **a** -- 进入插入模式，在光标下一个位置开始输入文本。
- **o**：在当前行的下方插入一个新行，并进入插入模式。
- **O** -- 在当前行的上方插入一个新行，并进入插入模式。
- **dd** -- 删除当前行。
- **yy** -- 复制当前行。
- **p**（小写） -- 粘贴剪贴板内容到光标下方。
- **P**（大写）-- 粘贴剪贴板内容到光标上方。
- **u** -- 撤销上一次操作。
- **Ctrl + r** -- 重做上一次撤销的操作。
- **:w** -- 保存文件。
- **:q** -- 退出 Vim 编辑器。
- **:q!** -- 强制退出Vim 编辑器，不保存修改。