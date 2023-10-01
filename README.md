# OS_2023
## https://v1.v2ai.top/link/o1sPd0pD5Ln14Elz?sub=3
1. 课外练习（不需要提交）

1）对照流程图，阅读程序，并在Linux下运行，确保完全读懂。
#include <stdio.h>
#include <unistd.h>
int main()
{
	int p1, p2;
	while ((p1 = fork()) == -1)
		;
	if (p1 == 0)
		putchar('b');
	else
	{
		while ((p2 = fork()) == -1)
			;
		if (p2 == 0)
			putchar('c');
		else
			putchar('a');
	}
	return 0;
}

2）对上述程序略加修改，如下，分析其运行结果，并在Linux下运行验证，确保完全弄懂。
#include <stdio.h>
#include <unistd.h>
int main()
{
	int p1, p2;
	while ((p1 = fork()) == -1)
		;
	if (p1 == 0)
	{
		putchar('b');
		fflush(stdout);
		sleep(2);
		putchar('b');
	}
	else
	{
		while ((p2 = fork()) == -1)
			;
		if (p2 == 0)
		{
			putchar('c');
			fflush(stdout);
			sleep(1);
			putchar('c');
		}
		else
		{
			putchar('a');
			fflush(stdout);
			sleep(3);
			putchar('a');
		}
	}
	return 0;
}

3）上述程序中，三个分支都调用了fflush()函数，把这三处调用都注释掉，分析运行结果，并在Linux下运行验证，确保完全弄懂。

4）对照流程图，阅读程序，分析运行结果，并在Linux下运行验证，确保完全读懂。


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	int pid;
	pid = fork();
	switch (pid)
	{
	case -1:
		printf("fork fail!\n");
		exit(1);
	case 0:
		sleep(3);
		execl("/bin/ls", "ls", "-1", "-color", NULL);
		sleep(30);
		printf("exec fail!\n");
		exit(1);
	default:
		wait(NULL);
		printf("ls completed !\n");
		exit(0);
	}
	return 0;
}

2. 程序分析

1）分析以下程序，LINE A这一行的输出是什么？
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int value = 5;
int main()
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{ /* child process */
		value += 15;
		return 0;
	}
	else if (pid > 0)
	{ /* parent process */
		wait(NULL);
		printf("PARENT: value = %d", value); /* LINE A */
		return 0;
	}
}

2）分析以下程序总共产生了多少个进程。
#include <stdio.h>
#include <unistd.h>
int main()
{
	/* fork a child process */
	fork();
	/* fork another child process */
	fork();
	/* and fork another */
	fork();
	return 0;
}

3. 选择题

1）对进程的管理和控制使用_____。
A. 指令                 B. 信号量
C. 原语                 D. 信箱

2）下列进程状态变化中，_____变化是不可能发生的。
A.等待→就绪         B.等待→运行
C.运行→等待         D.运行→就绪

3）当_____时，进程从执行状态转变为就绪状态。
A.等待的事件发生        B.时间片到
C.等待某一事件          D.进程被调度程序选中

4）下面所述步骤中，_____不是创建进程所必需的。
A.建立一个进程控制块
B.为进程分配内存
C.将进程控制块链入就绪队列
D.由调度程序为进程分配CPU

5）如果系统中有n个进程，则就绪队列中进程的个数最多为_____。
A. n          B. 1
C. n-1        D. n+1

6）下面对父进程和子进程的叙述不正确的是_____。
A. 撤消父进程之时，可以同时撤消其子进程
B. 父进程和子进程之间可以并发
C. 父进程可以等待所有子进程结束后再执行
D.父进程创建了子进程，因此父进程执行完了子进程才能运行

7）并发进程失去了封闭性是指_____。
A．并发进程的执行结果与速度无关
B．多个相对独立的进程以各自的速度向前推进
C．并发进程执行时，在不同时刻发生的错误
D．并发进程共享变量，其执行结果与速度有关

8）当一个进程处于_____的状态时，称其为等待状态
A．它正等待调度
B．它正等着协作进程的一个消息
C．它正等分给它一个时间片
D．它正等进入内存

9）一个进程被唤醒意味着_____ 。 
A．该进程重新占有了CPU
B．进程状态变为就绪 
C．它的优先权变为最大
D．其PCB移至就绪队列的队首

10）一个进程基本状态可以从其他两种基本状态转变过来，这个基本状态是_____。
A．执行状态        B．阻塞状态
C．就绪状态        D．撤销状态

11）下列选项中，导致创建新进程的操作是____。
Ⅰ 用户登录成功     Ⅱ 设备分配     Ⅲ 启动程序执行
A.仅Ⅰ和Ⅱ			B.仅Ⅱ和Ⅲ
C.仅Ⅰ和Ⅲ			D.Ⅰ、Ⅱ、Ⅲ

12）下列选项中，在用户态执行的是____。
A、命令解释程序  B、原语
C、进程调度程序  D、时钟中断处理程序

13）设系统中有n（n>2）个进程，且当前不在执行进程调度程序，试考虑下述4种情况，不可能发生的情况是_____。
A. 有1个运行进程，n-1个就绪进程，没有进程处于等待状态。
B. 有1个运行进程，没有就绪进程，n-1进程处于等待状态。
C. 有1个运行进程，有1个就绪进程，n-2进程处于等待状态。
D. 没有运行进程，有2个就绪进程，n个进程处于等待状态
