# Make的基本操作及makefile

make方法的操作:
通过指定规则(makefile)
逐条执行指令

# makefile的组成

具体形式如下

```bash
<target> : <prerequisites> 
[tab]  <commands>
```

"目标"是必需的，不可省略；"前置条件"和"命令"都是可选的，但是两者之中必须至少存在一个。

每条规则就明确两件事：构建目标的前置条件是什么，以及如何构建。下面就详细讲解，每条规则的这三个组成部分。

target:
target file name

```bash
clean:
	rm *.o
	
$ make clean 

.PHONY:clean
clean:
	rm  *.o temp
```

prerequisites:
```bash
result.txt: source.txt
	cp source.txt result.txt
	
source.txt:
	echo "this is the source" > source.txt
	
上面代码中，source.txt后面没有前置条件，就意味着它跟其他文件都无关，只要这个文件还不存在，每次调用make source.txt，它都会生成。

source: file1 file2 file3
上面代码中，source 是一个伪目标，只有三个前置文件，没有任何对应的命令
$ make source
等同于
$ make file1
$ make file2
$ make file3
```

commands:
需要注意的是，每行命令在一个单独的shell中执行。这些Shell之间没有继承关系。

```bash
var-lost:
    export foo=bar
    echo "foo=[$$foo]"
上面代码执行后，取不到foo的值。因为两行命令在两个不同的进程执行。一个解决办法是将两行命令写在一行，中间用分号分隔。
var-kept:
    export foo=bar; echo "foo=[$$foo]"
另一个解决办法是在换行符前加反斜杠转义。
var-kept:
    export foo=bar; \
    echo "foo=[$$foo]"
最后一个方法是加上.ONESHELL:命令。
.ONESHELL:
var-kept:
    export foo=bar; 
    echo "foo=[$$foo]"
```

# makefile的语法

### 3.1 注释

井号（#）在Makefile中表示注释。

> ```bash
> # 这是注释
> result.txt: source.txt
>     # 这是注释
>     cp source.txt result.txt # 这也是注释
> ```

### 3.2 回声（echoing）

正常情况下，make会打印每条命令，然后再执行，这就叫做回声（echoing）。

> ```bash
> test:
>     # 这是测试
> ```

执行上面的规则，会得到下面的结果。

> ```bash
> $ make test
> # 这是测试
> ```

在命令的前面加上@，就可以关闭回声。

> ```bash
> test:
>     @# 这是测试
> ```

现在再执行`make test`，就不会有任何输出。

由于在构建过程中，需要了解当前在执行哪条命令，所以通常只在注释和纯显示的echo命令前面加上@。

> ```bash
> test:
>     @# 这是测试
>     @echo TODO
> ```

### 3.3 通配符

通配符（wildcard）用来指定一组符合条件的文件名。Makefile 的通配符与 Bash 一致，主要有星号（*）、问号（？）和 [...] 。比如， *.o 表示所有后缀名为o的文件。

> ```bash
> clean:
>         rm -f *.o
> ```

### 3.4 模式匹配

Make命令允许对文件名，进行类似正则运算的匹配，主要用到的匹配符是%。比如，假定当前目录下有 f1.c 和 f2.c 两个源码文件，需要将它们编译为对应的对象文件。

> ```bash
> %.o: %.c
> ```

等同于下面的写法。

> ```bash
> f1.o: f1.c
> f2.o: f2.c
> ```

使用匹配符%，可以将大量同类型的文件，只用一条规则就完成构建。

### 3.5 变量和赋值符

Makefile 允许使用等号自定义变量。

> ```bash
> txt = Hello World
> test:
>     @echo $(txt)
> ```

上面代码中，变量 txt 等于 Hello World。调用时，变量需要放在 $( ) 之中。

调用Shell变量，需要在美元符号前，再加一个美元符号，这是因为Make命令会对美元符号转义。

> ```bash
> test:
>     @echo $$HOME
> ```

有时，变量的值可能指向另一个变量。

> ```bash
> v1 = $(v2)
> ```

上面代码中，变量 v1 的值是另一个变量 v2。这时会产生一个问题，v1 的值到底在定义时扩展（静态扩展），还是在运行时扩展（动态扩展）？如果 v2 的值是动态的，这两种扩展方式的结果可能会差异很大。

为了解决类似问题，Makefile一共提供了四个赋值运算符 （=、:=、？=、+=），它们的区别请看[StackOverflow](http://stackoverflow.com/questions/448910/makefile-variable-assignment)。

> ```bash
> VARIABLE = value
> # 在执行时扩展，允许递归扩展。
> 
> VARIABLE := value
> # 在定义时扩展。
> 
> VARIABLE ?= value
> # 只有在该变量为空时才设置值。
> 
> VARIABLE += value
> # 将值追加到变量的尾端。
> ```

### 3.6 内置变量（Implicit Variables）

Make命令提供一系列内置变量，比如，$(CC) 指向当前使用的编译器，$(MAKE) 指向当前使用的Make工具。这主要是为了跨平台的兼容性，详细的内置变量清单见[手册](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html)。

> ```bash
> output:
>     $(CC) -o output input.c
> ```

### 3.7 自动变量（Automatic Variables）

Make命令还提供一些自动变量，它们的值与当前规则有关。主要有以下几个。

**（1）$@**

$@指代当前目标，就是Make命令当前构建的那个目标。比如，`make foo`的 $@ 就指代foo。

> ```bash
> a.txt b.txt: 
>     touch $@
> ```

等同于下面的写法。

> ```bash
> a.txt:
>     touch a.txt
> b.txt:
>     touch b.txt
> ```

**（2）$<**

$< 指代第一个前置条件。比如，规则为 t: p1 p2，那么$< 就指代p1。

> ```bash
> a.txt: b.txt c.txt
>     cp $< $@ 
> ```

等同于下面的写法。

> ```bash
> a.txt: b.txt c.txt
>     cp b.txt a.txt 
> ```

**（3）$?**

$? 指代比目标更新的所有前置条件，之间以空格分隔。比如，规则为 t: p1 p2，其中 p2 的时间戳比 t 新，$?就指代p2。

**（4）$^**

$^ 指代所有前置条件，之间以空格分隔。比如，规则为 t: p1 p2，那么 $^ 就指代 p1 p2 。

**（5）$\***

$* 指代匹配符 % 匹配的部分， 比如% 匹配 f1.txt 中的f1 ，$* 就表示 f1。

**（6）$(@D) 和 $(@F)**

$(@D) 和 $(@F) 分别指向 $@ 的目录名和文件名。比如，$@是 src/input.c，那么$(@D) 的值为 src ，$(@F) 的值为 input.c。

**（7）$(<D) 和 $(<F)**

$(<D) 和 $(<F) 分别指向 $< 的目录名和文件名。

所有的自动变量清单，请看[手册](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)。下面是自动变量的一个例子。

> ```bash
> dest/%.txt: src/%.txt
>     @[ -d dest ] || mkdir dest
>     cp $< $@
> ```

上面代码将 src 目录下的 txt 文件，拷贝到 dest 目录下。首先判断 dest 目录是否存在，如果不存在就新建，然后，$< 指代前置文件（src/%.txt）， $@ 指代目标文件（dest/%.txt）。

### 3.8 判断和循环

Makefile使用 Bash 语法，完成判断和循环。

> ```bash
> ifeq ($(CC),gcc)
>   libs=$(libs_for_gcc)
> else
>   libs=$(normal_libs)
> endif
> ```

上面代码判断当前编译器是否 gcc ，然后指定不同的库文件。

> ```bash
> LIST = one two three
> all:
>     for i in $(LIST); do \
>         echo $$i; \
>     done
> 
> # 等同于
> 
> all:
>     for i in one two three; do \
>         echo $i; \
>     done
> ```

上面代码的运行结果。

> ```bash
> one
> two
> three
> ```

### 3.9 函数

Makefile 还可以使用函数，格式如下。

> ```bash
> $(function arguments)
> # 或者
> ${function arguments}
> ```

Makefile提供了许多[内置函数](http://www.gnu.org/software/make/manual/html_node/Functions.html)，可供调用。下面是几个常用的内置函数。

**（1）shell 函数**

shell 函数用来执行 shell 命令

> ```bash
> srcfiles := $(shell echo src/{00..99}.txt)
> ```

**（2）wildcard 函数**

wildcard 函数用来在 Makefile 中，替换 Bash 的通配符。

> ```bash
> srcfiles := $(wildcard src/*.txt)
> ```

**（3）subst 函数**

subst 函数用来文本替换，格式如下。

> ```bash
> $(subst from,to,text)
> ```

下面的例子将字符串"feet on the street"替换成"fEEt on the strEEt"。

> ```bash
> $(subst ee,EE,feet on the street)
> ```

下面是一个稍微复杂的例子。

> ```bash
> comma:= ,
> empty:=
> # space变量用两个空变量作为标识符，当中是一个空格
> space:= $(empty) $(empty)
> foo:= a b c
> bar:= $(subst $(space),$(comma),$(foo))
> # bar is now `a,b,c'.
> ```

**（4）patsubst函数**

patsubst 函数用于模式匹配的替换，格式如下。

> ```bash
> $(patsubst pattern,replacement,text)
> ```

下面的例子将文件名"x.c.c bar.c"，替换成"x.c.o bar.o"。

> ```bash
> $(patsubst %.c,%.o,x.c.c bar.c)
> ```

**（5）替换后缀名**

替换后缀名函数的写法是：变量名 + 冒号 + 后缀名替换规则。它实际上patsubst函数的一种简写形式。

> ```bash
> min: $(OUTPUT:.js=.min.js)
> ```

上面代码的意思是，将变量OUTPUT中的后缀名 .js 全部替换成 .min.js 。

