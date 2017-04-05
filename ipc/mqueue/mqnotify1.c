#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <errno.h>

volatile sig_atomic_t mqflag;
static void sig_usr1(int);

int main(int argc, char *argv[])
{
	mqd_t mqd;
	void *buff;
	ssize_t n;
	sigset_t zeromask, newmask, oldmask;
	struct mq_attr attr;
	struct sigevent sigev;

	if (argc != 2)
		printf("Usage: notify <name>");
	
	mqd = mq_open(argv[1], O_RDONLY | O_NONBLOCK);
	mq_getattr(mqd, &attr);
	buff = malloc(attr.mq_msgsize);

	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigemptyset(&oldmask);
	sigaddset(&newmask, SIGUSR1);
	
	signal(SIGUSR1, sig_usr1);
	sigev.sigev_notify = SIGEV_SIGNAL;
	sigev.sigev_signo = SIGUSR1;
	mq_notify(mqd, &sigev);

	for(;;) {
		sigprocmask(SIG_BLOCK, &newmask, &oldmask);
		while(mqflag == 0) 
			sigsuspend(&zeromask);
		mqflag = 0;

		mq_notify(mqd, &sigev);
		while ( (n=mq_receive(mqd, buff, attr.mq_msgsize, NULL)) >= 0) {
			printf("read %ld bytes\n", (long)n);
		}
		if (errno != EAGAIN) 
			printf("mq_receive error");
		sigprocmask(SIG_UNBLOCK, &newmask, NULL);
	}
	exit(0);
}

static void
sig_usr1(int signo)
{
	mqflag = 1;
	return ;
}
