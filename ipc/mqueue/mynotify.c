#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <fcntl.h>
#include <signal.h>

struct sigevent sigev;
mqd_t mqd;
struct mq_attr attr;
void *buf;

int main()
{
	if (argc != 2) {
		printf("usage: notify <name>\n");
		exit(EXIT_FAILURE);
	}
	mqd = mq_open(argv[1], O_RDONLY);
	mq_getattr(mqd, &attr);

	buf = malloc(attr.mq_msgsize);

sigev.sigev_notify = SIGEV_SIGNAL;
sigev.sigev_signo = SIGUSR1;

sigev.sigev_notify
sigev.sigev_signo
	signal(SIGUSR1, sig_usr1);

	sigev.sigev_notify = SIGEV_SIGNAL;
	sigev.sigev_signo = SIGUSR1;
	mq_notify(mqd, &sigev);

	for(;;) 
		pause();
	exit(0);
}

static void sig_usr1(int signo)
{
	ssize_t n;
	mq_notify(mqd, &sigev);
	n = mq_receive();
}
