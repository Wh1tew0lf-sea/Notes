# **LEC 1 (ab):** [Introduction](https://pdos.csail.mit.edu/6.828/2021/slides/6s081-lec-intro.pdf) and [examples](https://pdos.csail.mit.edu/6.828/2021/lec/l-overview/)

(handouts: [xv6 book](https://pdos.csail.mit.edu/6.828/2021/xv6/book-riscv-rev2.pdf); 2020: [notes](https://pdos.csail.mit.edu/6.828/2021/lec/l-overview.txt), [video](https://youtu.be/L6YqHxYHa7A))

**Preparation**: [Read chapter 1](https://pdos.csail.mit.edu/6.828/2021/xv6/book-riscv-rev2.pdf) (for your amusement: [Unix](https://www.youtube.com/watch?v=tc4ROCJYbm0))
**Homework 1 due:** [Question](https://pdos.csail.mit.edu/6.828/2021/homework/q.html)
**Assignment**: [Lab util: Unix utilities](https://pdos.csail.mit.edu/6.828/2021/labs/util.html)



## Notes

Why Hard/Interesting ?

+ unforgiving
+ tensions
+ + Efficient Abstract
  + powerful simple
  + Flexible Secure

### system call

#### xv6 : simple Unix

risc-v qemu machine

<img src="LEC1.assets/image-20230516214201456.png" alt="image-20230516214201456" style="zoom:33%;" />

<img src="LEC1.assets/image-20230516214213227.png" alt="image-20230516214213227" style="zoom:33%;" />

<img src="LEC1.assets/image-20230516214246674.png" alt="image-20230516214246674" style="zoom:33%;" />



# xv6: Reading chapter 1

An operating system manages and abstracts the low-level hardware.

for a application, different hardware,one environment.
for applications ,run at the same time while occupy the whole environment(as it appears),share data or work together.

Since system calls have privileges, supposed to separate user and kernel space and    

# Lab: Xv6 and Unix utilities 实验室：Xv6 和 Unix 实用程序

This lab will familiarize you with xv6 and its system calls.