## FS Shell

调用文件系统(FS)Shell命令应使用 bin/hadoop fs <args>的形式。 所有的的FS shell命令使用URI路径作为参数。URI格式是*scheme://authority/path*。对HDFS文件系统，scheme是*hdfs*，对本地文件系统，scheme是*file*。其中scheme和authority参数都是可选的，如果未加指定，就会使用配置中指定的默认scheme。一个HDFS文件或目录比如*/parent/child*可以表示成*hdfs://namenode:namenodeport/parent/child*，或者更简单的*/parent/child*（假设你配置文件中的默认值是*namenode:namenodeport*）。大多数FS Shell命令的行为和对应的Unix Shell命令类似，不同之处会在下面介绍各命令使用详情时指出。出错信息会输出到*stderr*，其他信息输出到*stdout*。



### cat

使用方法：hadoop fs -cat URI [URI …]

将路径指定文件的内容输出到*stdout*。

示例：

- hadoop fs -cat hdfs://host1:port1/file1 hdfs://host2:port2/file2
- hadoop fs -cat file:///file3 /user/hadoop/file4

返回值：
成功返回0，失败返回-1。



### chgrp

使用方法：hadoop fs -chgrp [-R] GROUP URI [URI …] Change group association of files. With -R, make the change recursively through the directory structure. The user must be the owner of files, or else a super-user. Additional information is in the [Permissions User Guide](https://hadoop.apache.org/docs/r1.0.4/cn/hdfs_permissions_guide.html). -->

改变文件所属的组。使用-R将使改变在目录结构下递归进行。命令的使用者必须是文件的所有者或者超级用户。更多的信息请参见[HDFS权限用户指南](https://hadoop.apache.org/docs/r1.0.4/cn/hdfs_permissions_guide.html)。



### chmod

使用方法：hadoop fs -chmod [-R] <MODE[,MODE]... | OCTALMODE> URI [URI …]

改变文件的权限。使用-R将使改变在目录结构下递归进行。命令的使用者必须是文件的所有者或者超级用户。更多的信息请参见[HDFS权限用户指南](https://hadoop.apache.org/docs/r1.0.4/cn/hdfs_permissions_guide.html)。



### chown

使用方法：hadoop fs -chown [-R] [OWNER][:[GROUP]] URI [URI ]

改变文件的拥有者。使用-R将使改变在目录结构下递归进行。命令的使用者必须是超级用户。更多的信息请参见[HDFS权限用户指南](https://hadoop.apache.org/docs/r1.0.4/cn/hdfs_permissions_guide.html)。



### copyFromLocal

使用方法：hadoop fs -copyFromLocal <localsrc> URI

除了限定源路径是一个本地文件外，和[**put**](https://hadoop.apache.org/docs/r1.0.4/cn/hdfs_shell.html#putlink)命令相似。



### copyToLocal

使用方法：hadoop fs -copyToLocal [-ignorecrc] [-crc] URI <localdst>

除了限定目标路径是一个本地文件外，和[**get**](https://hadoop.apache.org/docs/r1.0.4/cn/hdfs_shell.html#getlink)命令类似。



### cp

使用方法：hadoop fs -cp URI [URI …] <dest>

将文件从源路径复制到目标路径。这个命令允许有多个源路径，此时目标路径必须是一个目录。
示例：

- hadoop fs -cp /user/hadoop/file1 /user/hadoop/file2
- hadoop fs -cp /user/hadoop/file1 /user/hadoop/file2 /user/hadoop/dir

返回值：

成功返回0，失败返回-1。



### du

使用方法：hadoop fs -du URI [URI …]

显示目录中所有文件的大小，或者当只指定一个文件时，显示此文件的大小。
示例：
hadoop fs -du /user/hadoop/dir1 /user/hadoop/file1 hdfs://host:port/user/hadoop/dir1
返回值：
成功返回0，失败返回-1。



### dus

使用方法：hadoop fs -dus <args>

显示文件的大小。



### expunge

使用方法：hadoop fs -expunge

清空回收站。请参考[HDFS设计](https://hadoop.apache.org/docs/r1.0.4/cn/hdfs_design.html)文档以获取更多关于回收站特性的信息。



### get

使用方法：hadoop fs -get [-ignorecrc] [-crc] <src> <localdst>

复制文件到本地文件系统。可用-ignorecrc选项复制CRC校验失败的文件。使用-crc选项复制文件以及CRC信息。

示例：

- hadoop fs -get /user/hadoop/file localfile
- hadoop fs -get hdfs://host:port/user/hadoop/file localfile

返回值：

成功返回0，失败返回-1。



### getmerge

使用方法：hadoop fs -getmerge <src> <localdst> [addnl]

接受一个源目录和一个目标文件作为输入，并且将源目录中所有的文件