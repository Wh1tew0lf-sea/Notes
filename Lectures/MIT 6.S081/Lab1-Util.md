# Lab1: Xv6 and Unix utilities

**This lab will familiarize you with xv6 and its system calls.**

## Boot xv6

After git clone and git checkout util ,input the magic code :`make qemu`.Then a simulator which is booted by risc-V.



## sleep

```c
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(2, "Usage: sleep seconds\n");
		exit(1);
	}
	int time = atoi(argv[1]);
	sleep(time);
	
	exit(0);
}
```

## pingpong

```c
int p[2];
  char buf[100];
  pipe(p);

  int pid = fork();
  if (pid == 0) {//child
    write(p[1], “ping”, 4);
    printf(“Thread id %d: received ping\n”, getpid());
  } 
  else {//parent
    wait(0);
    read(p[0], buf, 4);
    printf(“Thread id %d: received pong\n”, getpid());
  }
```

## primes

```c

```

