# 多线程——生产者&消费者模型

## 需要学习的知识：
- [互斥锁](https://book.itheima.net/course/223/1277519158031949826/1277528625427521539)
- [atoi()函数](http://www.cplusplus.com/reference/cstdlib/atoi/?kw=atoi)
- [pthread.h库的使用](https://blog.csdn.net/lileiyuyanqin/article/details/78212305)
- [信号量库semaphore.h](https://blog.csdn.net/tietao/article/details/6825390)
- [gdb调试-set指令](https://www.cnblogs.com/wuyuegb2312/archive/2013/03/29/2987025.html)
## 一些小问题

### 为什么要同时用到互斥锁和信号量？
> - 互斥锁是为了保证只能有一个进程在临界区修改值。生产者和消费者都在修改同一个变量，如果同时修改结果会产生混乱。
> - 信号量是为了保证消费者有内容去消费，如果队列为空，消费者没有能够消费的内容，那么就依靠信号量来阻塞消费者的进程，直到生产者生产出新的内容供给消费者。

### 编译时报错undefined reference to `sem'
> -由于pthread.h不是linux内置库，编译时需要加上-pthread指令

### [循环队列](https://www.jianshu.com/p/411f2d64c2c6)的头和尾怎么指向的
> - rear指向一个空的位置，这个位置没有数据储存，表示将要插入。而front指向头指针，即队头数据储存的位置。

### 命令行参数的问题
> - 命令行参数argv[0]储存的是程序的名称，不是第一个参数。
