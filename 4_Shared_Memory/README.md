# 共享内存(Shared Memory)

> 让多个进程访问同一块内存，当一个进程往共享内存块中写入了数据，共享这个内存区域的所有进程就都可以看到其中的内容。

优点：

- 无需在用户态和内核态之间进行拷贝，效率最高，适合于大文件的传输

缺点：

- 多进程共同操作一块内存，会出现读写冲突问题。实际使用中往往需要用信号量等手段来保证数据同步。
