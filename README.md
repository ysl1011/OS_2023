程序如下，填写其中空缺的部分，并提交关键代码和运行结果的截图（要求输出中增加学号姓名）。
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/wait.h>

#define MSGKEY 75

struct msgform
{
	long mtype;
	char mtext[1000];
} msg;
int msgqid;

void run_server()
{
	// 请填写
}

void run_client()
{
	// 请填写
	for (…)
	{
		// 请填写
		sleep(1);
	}
}

int main()
{
	int pid;
	while ((pid = fork()) == -1)
		;
	if (pid == 0)
	{
		sleep(1);
		run_client();
		exit(0);
	}
	else
	{
		run_server();
	}
	wait(NULL);
	return 0;
}
