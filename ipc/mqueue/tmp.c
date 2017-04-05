

union sigval {
	int sival_int;
	void *sival_ptr;
}

struct sigevent {
	int sigev_notify;
	int sigev_signo;

	union sigval sigev_value;

	void (*sigev_notify_function)(union sigval);
	pthread_attr_t *sigev_notify_attributed;
}

struct sigevent {
	int sigev_notify;
	int sigev_signo;

	union sigval sigev_value;
	void (*sigev_notify_function)(union sigval);
}
