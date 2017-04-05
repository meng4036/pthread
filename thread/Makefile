
TARGETS = create mutex cond mymutex
OBJS = pthread.o mutex.o cond.o mumutex.o

CFLAG = -lpthread

%.o: %.c
	gcc -c $< -o $@ $(CFLAG)

all: $(TARGETS)

create: pthread.o
	gcc $(CFLAG) -o $@ $<

mutex: mutex.o
	gcc $(CFLAG) -o $@ $<

mymutex: mymutex.o
	gcc $(CFLAG) -o $@ $<

cond: cond.o
	gcc $(CFLAG) -o $@ $<

clean: 
	rm -f $(OBJS) $(TARGETS)
