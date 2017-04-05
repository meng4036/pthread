
CFLAG = -lrt

%.o: %c
	gcc -c -o $@ $< $(CFLAG)

all: create send receive notify notifysig1 unlink

unlink: mqunlink.o
	gcc -o $@ $< $(CFLAG)

create: mqcreate.o
	gcc -o $@ $< $(CFLAG)

send: mqsend.o
	gcc -o $@ $< $(CFLAG)

receive: mqreceive.o
	gcc -o $@ $< $(CFLAG)

notify: mqnotify.o
	gcc -o $@ $< $(CFLAG)

notifysig1: mqnotify1.o
	gcc -o $@ $< $(CFLAG)

clean:
	rm *.o create send receive notify
