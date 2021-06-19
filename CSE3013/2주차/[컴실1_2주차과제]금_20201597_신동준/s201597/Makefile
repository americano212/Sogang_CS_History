cc=gcc
cflags = -W -g
target = main

objects = main.o div.o prt.o

$(target) : $(objects)
	$(cc) $(cflags) -o $(target) $(objects)

%.o : %.c
	$(cc) $(cflags) -c -o $@ $<

main.o div.o prt.o : Header.h

.PHONY : clean
clean :
	rm $(target) $(objects)
