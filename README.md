# Interprocess-communication

> 进程间通信及实现示例

### 常用IPC机制

- 管道
- 命名管道
- 消息队列
- 共享内存
- 信号量
- 信号
- Socket

### 选择方法

* 信息简短、通信频率高：适合管道、命名管道和消息队列。进一步细分：字节流的消息用管道、命名管道；每条消息包含多种基本类型，使用消息队列自定义结构体较为方便。
* 信息体量非常庞大，读写频率较高：此类信息拷贝代价极大，适合共享内存+信号量。多进程使用一块共享内存，免去拷贝开销；信号量实现同步机制，避免多进程同时修改出现冲突。
* 进程间仅需极为简单的信息传递：要传递的信息十分简单，可以用信号，仅依靠自定义几个信号即可满足。
* 一般情况：socket适应面非常广，API丰富好用，可移植性强，因此除非应用场景十分契合其他通信方式的特点，一般均优先考虑使用socket通信。进一步细分：若可能扩展到多机器上，选用TCP，尽管会牺牲一点效率；若能够确定应用未来也仅会单机使用，可以使用本地socket，效率可以媲美甚至超过管道。

