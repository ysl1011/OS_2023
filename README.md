https://zhuanlan.zhihu.com/p/625962093

https://blog.csdn.net/frothmoon/article/details/90341693

程序如下，填写其中空缺的部分，并提交关键代码和运行结果的截图（要求输出中增加学号姓名）。
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SHMKEY 75
#define SEMFULL 6666
#define SEMEMPTY 7777
/* defined in sem.h
struct sembuf{
	short sem_num;
	short sem_op;
	short sem_flg;
};
*/
union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *arry;
};

int shmid, pid, semid_full, semid_empty;
struct sembuf sem_b;
int *addr;

void client()
{
	int i;
	shmid = shmget(SHMKEY, 1024, 0777 | IPC_CREAT);
	addr = (int *)shmat(shmid, 0, 0);
	for (i = 9; i >= 0; i--)
	{
		// 请填写此处的程序
	}
	exit(0);
}

void server()
{
	shmid = shmget(SHMKEY, 1024, 0777 | IPC_CREAT);
	addr = (int *)shmat(shmid, 0, 0);
	do
	{
		// 请填写此处的程序
	} while (*addr);
	shmctl(shmid, IPC_RMID, 0);
	exit(0);
}

int main()
{
	union semun sem_union;
	semid_empty = semget((key_t)SEMEMPTY, 1, 0777 | IPC_CREAT);
	sem_union.val = 1;
	semctl(semid_empty, 0, SETVAL, sem_union);
	semid_full = semget((key_t)SEMFULL, 1, 0777 | IPC_CREAT);
	sem_union.val = 0;
	semctl(semid_full, 0, SETVAL, sem_union);
	sem_b.sem_num = 0;
	sem_b.sem_flg = SEM_UNDO;

	while ((pid = fork()) == -1)
		;
	if (!pid)
		server();
	system("ipcs -s");
	while ((pid = fork()) == -1)
		;
	if (!pid)
		client();
	wait(0);
	wait(0);
	semctl(semid_empty, 0, IPC_RMID, sem_union);
	semctl(semid_full, 0, IPC_RMID, sem_union);
	return 0;
}
