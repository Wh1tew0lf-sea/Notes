# C++（STL）容器适配器

![C++ STL容器适配器](STL_容器适配器.assets/2-20052209240O59.gif)容器适配器是一个封装了序列容器的类模板，它在一般序列容器的基础上提供了一些不同的功能。之所以称作适配器类，是因为它可以通过适配容器现有的接口来提供不同的功能。

本章将介绍 3 种容器适配器，分别是 stack、queue、priority_queue：

1. stack<T>：是一个封装了 deque<T> 容器的适配器类模板，默认实现的是一个后入先出（Last-In-First-Out，LIFO）的压入栈。stack<T> 模板定义在头文件 stack 中。
2. queue<T>：是一个封装了 deque<T> 容器的适配器类模板，默认实现的是一个先入先出（First-In-First-Out，LIFO）的队列。可以为它指定一个符合确定条件的基础容器。queue<T> 模板定义在头文件 queue 中。
3. priority_queue<T>：是一个封装了 vector<T> 容器的适配器类模板，默认实现的是一个会对元素排序，从而保证最大元素总在队列最前面的队列。priority_queue<T> 模板定义在头文件 queue 中。