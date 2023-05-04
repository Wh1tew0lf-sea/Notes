线程>窗口>窗格

一个线程多个窗口，一个窗口可以多个窗格

线程(session):

+ tmux new -s <name>

+ tmux detach(not delete,in background)
+ tmux attach -t <name>
+ tmux  switch -t <name>
+ tmux ls
+ C-b + d 分离会话
+ C-b + s 列出所有会话
+ C-b + $ 重命名会话

窗口(window)：

+ C-b + c 新窗口
+ C-b + n/p/(0-9) 切换窗口
+ C-b + , 重命名窗口
+ C-d 关闭窗口
+ C-b + w 选择窗口

窗格（pane)：

+ C-b + %/" 左右/上下开窗格
+ C-b + <arrow key> 上下左右换
+ C-b + ;/o 上/下一个窗格
+ C-b + ! 将目前窗格变成一个窗口
+ C-b + x 关闭目前窗格 

+ C-b +z 全屏目前窗格，再z可以回来

+ C-b C-<arrow key> 改变窗格大小