CC = gcc

TARGETS = test01 test02 test 03
CFLAGS = -pthread
OBJS = test01.o


%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

test01: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJS) $(TARGETS)

run:
	test01
	test02
	test03

