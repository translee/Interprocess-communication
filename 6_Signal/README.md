# 信号(Signal)

> 信号是由用户、系统或者进程发送给目标进程的信息，以通知目标进程某个状态的改变或异常。与信号量一字之差，但二者是完全不同的东西。

优点：

- 异步通信
- Linux系统自身也广泛应用，如键盘输入Ctrl+Z产生一个SIGTSTP信号中止当前进程

缺点：

- 发送方需要指定接收方进程的PID，或输入0发送给同组所有进程
- 传递信息量有限，需约定好信号含义，不像管道可以收发任意字符
