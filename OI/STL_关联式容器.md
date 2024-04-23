# C++ STL关联式容器详解

![STL关联式容器](STL_关联式容器.assets/2-200522091J4332.gif)本章将介绍 STL 标准库中另一类容器，即关联式容器，包括 map、multimap、set 以及 multiset 这 4 种容器。

和序列式容器不同的是，关联式容器在存储元素时还会为每个元素在配备一个键，整体以键值对的方式存储到容器中。相比前者，关联式容器可以通过键值直接找到对应的元素，而无需遍历整个容器。另外，关联式容器在存储元素，默认会根据各元素键值的大小做升序排序。

相比其它类型容器，关联式容器查找、访问、插入和删除指定元素的效率更高。

# C++ STL pair用法详解

我们知道，关联式容器存储的是“键值对”形式的数据，比如：

<"C语言教程", "http://c.biancheng.net/c/">
<"[Python](https://c.biancheng.net/python/)教程", "http://c.biancheng.net/python/">
<"[Java](https://c.biancheng.net/java/)教程", "http://c.biancheng.net/java/">

如上所示，每行都表示一个键值对，其中第一个元素作为键（key），第二个元素作为值（value）。

> 注意，基于各个关联式容器存储数据的特点，只有各个键值对中的键和值全部对应相等时，才能使用 set 和 multiset 关联式容器存储，否则就要选用 map 或者 multimap 关联式容器。

考虑到“键值对”并不是普通类型数据，[C++](https://c.biancheng.net/cplus/) [STL](https://c.biancheng.net/stl/) 标准库提供了 pair 类模板，其专门用来将 2 个普通元素 first 和 second（可以是 C++ 基本数据类型、结构体、类自定的类型）创建成一个新元素`<first, second>`。通过其构成的元素格式不难看出，使用 pair 类模板来创建“键值对”形式的元素，再合适不过。

注意，pair 类模板定义在`<utility>`头文件中，所以在使用该类模板之前，需引入此头文件。另外值得一提的是，在 C++ 11 标准之前，pair 类模板中提供了以下 3 种构造函数：

```
#1) 默认构造函数，即创建空的 pair 对象pair();#2) 直接使用 2 个元素初始化成 pair 对象pair (const first_type& a, const second_type& b);#3) 拷贝（复制）构造函数，即借助另一个 pair 对象，创建新的 pair 对象template<class U, class V> pair (const pair<U,V>& pr);
```

在 C++ 11 标准中，在引入[右值引用](https://c.biancheng.net/view/439.html)的基础上，pair 类模板中又增添了如下 2 个构造函数：

```
#4) 移动构造函数template<class U, class V> pair (pair<U,V>&& pr);#5) 使用右值引用参数，创建 pair 对象template<class U, class V> pair (U&& a, V&& b);
```

> 除此之外，C++ 11 标准中 pair 类模板还新增加了如下一种构造函数：`pair (piecewise_construct_t pwc, tuple<Args1...> first_args, tuple<Args2...> second_args);`
>
> ，该构造 pair 类模板的方式很少用到，因此本节不再对其进行详细介绍，感兴趣的读者可自行查阅资料。

下面程序演示了以上几种创建 pair 对象的方法：

```c++
#include <iostream>
#include <utility>      // pair
#include <string>       // string
using namespace std;
int main() {    // 调用构造函数 1，也就是默认构造函数    
    pair <string, double> pair1;    // 调用第 2 种构造函数    
    pair <string, string> pair2("STL教程","http://c.biancheng.net/stl/");      // 调用拷贝构造函数    
    pair <string, string> pair3(pair2);    //调用移动构造函数    
    pair <string, string> pair4(make_pair("C++教程", "http://c.biancheng.net/cplus/"));    // 调用第 5 种构造函数    
    pair <string, string> 
    pair5(string("Python教程"), string("http://c.biancheng.net/python/"));         
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;    
    cout << "pair2: "<< pair2.first << " " << pair2.second << endl;    
    cout << "pair3: " << pair3.first << " " << pair3.second << endl;    
    cout << "pair4: " << pair4.first << " " << pair4.second << endl;    
    cout << "pair5: " << pair5.first << " " << pair5.second << endl;    return 0;}
```

程序输出结果为：

pair1: 0
pair2: STL教程 http://c.biancheng.net/stl/
pair3: STL教程 http://c.biancheng.net/stl/
pair4: C++教程 http://c.biancheng.net/cplus/
pair5: Python教程 http://c.biancheng.net/python/

上面程序在创建 pair4 对象时，调用了 make_pair() 函数，它也是 <utility> 头文件提供的，其功能是生成一个 pair 对象。因此，当我们将 make_pair() 函数的返回值（是一个临时对象）作为参数传递给 pair() 构造函数时，其调用的是移动构造函数，而不是拷贝构造函数。

在上面程序的基础上，C++ 11 还允许我们手动为 pair1 对象赋值，比如：

```
pair1.first = "Java教程";pair1.second = "http://c.biancheng.net/java/";cout << "new pair1: " << pair1.first << " " << pair1.second << endl;
```

执行结果为：

new pair1: Java教程 http://c.biancheng.net/java/

同时，上面程序中 pair4 对象的创建过程，还可以写入如下形式，它们是完全等价的：

```
pair <string, string> pair4 = make_pair("C++教程", "http://c.biancheng.net/cplus/");cout << "pair4: " << pair4.first << " " << pair4.second << endl;
```

`<utility>`头文件中除了提供创建 pair 对象的方法之外，还为 pair 对象重载了 <、<=、>、>=、==、!= 这 6 的运算符，其运算规则是：对于进行比较的 2 个 pair 对象，先比较 pair.first 元素的大小，如果相等则继续比较 pair.second 元素的大小。

> 注意，对于进行比较的 2 个 pair 对象，其对应的键和值的类型比较相同，否则将没有可比性，同时编译器提示没有相匹配的运算符，即找不到合适的重载运算符。

举个例子：

```
#include <iostream>#include <utility>      // pair#include <string>       // stringusing namespace std;int main() {    pair <string, int> pair1("STL教程", 20);    pair <string, int> pair2("C++教程", 20);    pair <string, int> pair3("C++教程", 30);    //pair1和pair2的key不同，value相同    if (pair1 != pair2) {        cout << "pair != pair2" << endl;    }    //pair2和pair3的key相同，value不同    if (pair2 != pair3) {        cout << "pair2 != pair3" << endl;    }    return 0;}
```

程序执行结果为：

pair != pair2
pair2 != pair3

最后需要指出的是，pair类模板还提供有一个 swap() 成员函数，能够互换 2 个 pair 对象的键值对，其操作成功的前提是这 2 个 pair 对象的键和值的类型要相同。例如：

```
#include <iostream>#include <utility>      // pair#include <string>       // stringusing namespace std;int main() {    pair <string, int> pair1("pair", 10);                       pair <string, int> pair2("pair2", 20);    //交换 pair1 和 pair2 的键值对    pair1.swap(pair2);    cout << "pair1: " << pair1.first << " " << pair1.second << endl;    cout << "pair2: " << pair2.first << " " << pair2.second << endl;    return 0;}
```

程序执行结果为：

pair1: pair2 20
pair2: pair 10