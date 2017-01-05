#include "config.h"
#include "deamon.h"

void mws_deamon()
{
	pid_t pid;

	//忽略终端I/O信号,STOP信号
	//signal(SIGTTOU, SIG_IGN);
	//signal(SIGTTIN, SIG_IGN);
	//signal(SIGTSTP, SIG_IGN);
	//signal(SIGHUP, SIG_IGN);
	
	pid = fork();//create process
	if(0==pid)
	{
		//child process
		printf("deamon process ID:%d\n", getpid());
	}
	else if(pid<0)
	{
		//create fail
		printf("Process create fail!!!\n");
		exit(0);
	}
	else
	{
		//parent process
		exit(0);//exit, child process deamon proceess
	}


	//创建一个新的进程组,在这个新的进程组中
	//子进程成为这个进程组的首进程,以使该进程脱离所有终端
	setsid();

	//在次创建一个子进程退出父进程,保证该进程不是进程组长,同时
	//让该进程无法再打开一个新的终端
	pid = fork();
	if(pid>0)
	{
		//parent process
		exit(0);//exit, child process deamon proceess
	}
	else if(pid<0)
	{
		//create fail
		printf("Process create fail!!!\n");
		exit(0);
	}
	else
	{
		printf("deamon process ID:%d\n", getpid());
	}


	//关闭所有从父进程继承的不在需要的文件描述符(有待研究)
	//int i;
	//for(i=1; i<NOFILE; close(i++));
	//printf("TD:%d\n",NOFILE);
	
	//改变工作目录,使得进程不与任何文件系统联系
	chdir("/");
	
	//将文件屏蔽设置为0
	umask(0);

	//忽略SIGCHLD信号
	signal(SIGCHLD, SIG_IGN);
}
