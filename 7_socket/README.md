# 套接字(Socket)

> Socket原本专为网络通信设计，如服务器上的一个进程与客户端的一个进程就可以使用socket进行通信。作为一种特例，单机上的两个进程当然也可用TCP/UDP socket通信。如果仅用于单机通信，还可使用专为IPC发展出的本地socket，即UNIX domain socket(UDS)。由于本地通信不需要网络协议栈，不需要打包拆包、计算校验和等因而进行了一定的优化使UDS通信的效率能达到较高水平。

优点：

- 全双工通信
- API接口丰富，自带同步机制，使用方便
- 可以在不同主机的进程间通信，分布式应用程序必选

缺点：

- 使用上稍稍复杂一点



### 附录：

> TCP socket 和本地socket使用上的差别

```c++
// 1.套接字创建
int listenFd = socket(AF_UNIX, SOCK_STREAM, 0); // UNIX domain Socket
int listenFd = socket(AF_INET, SOCK_STREAM, 0); // TCP IPV4
// 本地套接字第一个参数用AF_UNIX、AF_LOCAL、PF_UNIX、PF_LOCAL都可以，他们的意义有细微差别，但是在内核的宏定义值是一样的
// 本地套接字第二个参数选字节流还是数据报无所谓，只是占个位置不起作用
// 2.sockaddr绑定
struct sockaddr_un; // UNIX domain Socket用此结构体存储地址(一个本地socket文件)
struct sockaddr_in; // TCP Socket用此结构体存储地址(ip+端口号)
// 本地套接字需要创建一个本地领域文件，因此bind前需要多一步确认domain文件原本不存在
struct sockaddr_un addr;
addr.sun_family = AF_UNIX;
const char* domainPath = "/tmp/myUDS.domain"
strncpy(addr.sun_path, domainPath, sizeof(addr.sun_path) - 1);
unlink(domainPath);
bind(listenFd, (struct sockaddr*)&addr, sizeof(addr));
// 这样确保该文件在bind时才新创建

// 剩余部分基本就都一样了，listen、accept以及收发API都是类似的用法
```

