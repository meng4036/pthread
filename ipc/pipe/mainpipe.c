#include <unistd.h>
#include <linux/types.h>

void server(int reader, int writer);
void client(int reader, int writer);

int main(int argc, char *argv[])
{
	int pipe1[2], pipe2[2];
	pid_t child_pid;

	popen(pipe1);
	popen(pipe2);

	if ((child_pid = fork()) == 0) {
		close(pipe1[1]);
		close(pipe2[0]);
		
		server(pipe1[0], pipe2[1]);

		exit(0);
	}

	close(pipe1[0]);
	close(pipe2[1]);

	client(pipe2[0], pipe1[1]);

	waitpid(child_pid, NULL, 0);

	exit(0);
}
