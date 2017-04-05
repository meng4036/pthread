CC = gcc

TARGETS = semcreate semunlink semgetvalue semwait sempost
CFLAGS = -lrt -g

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(TARGETS)

clean:
	rm  $(TARGETS)

run:
	test01
	test02
	test03

