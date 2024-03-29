# 信号量(Semaphore)

> 信号量的使用主要是用来保护共享资源，使得资源在一个时刻只被一个进程（线程）所占用。信号量的引用计数为正，说明本进程可以锁定并使用，锁定后值减1，若计数值为0，说明有其他进程占用，需要等待。信号量是原子性的，因此不会出现两个进程同时对计数值进行操作导致占用冲突。

优点：

- 可以用于进程间同步

缺点：

- 信号量自身无法携带更多信息，不以传送数据为主要目的，主要用来保护共享资源，通常会配合共享内存一起使用



### 附录：

> 信号量和互斥锁的异同

* 信号量和互斥锁都依赖于操作系统保证其原子性(保证同时刻只有一个进程/线程取得访问权)，都被用来解决同步问题。

* 信号量存在于内核中，天然支持跨进程，可以用于进程间/线程间；互斥锁如std::mutex和普通变量一样存在于单一进程，主要用于线程间同步。
* 互斥锁只能由单一线程访问；信号量内部有一个计数器，初值设的大于1就可以同时被多进程同时访问，当然，最常用的还是设为1，这种也叫做二进制信号量。

* 使用场景不同：互斥锁侧重于资源锁定，该资源一个时刻只能被一个线程占用；信号量不一定是资源的锁定，其更侧重流程上的概念，如进程A点灯并执行自己的任务，此时B等待，A完成任务后灭灯，此时进程B点灯并执行自己的任务。进程A、B未必使用同一资源，只是流程上需要二者的先后顺序。