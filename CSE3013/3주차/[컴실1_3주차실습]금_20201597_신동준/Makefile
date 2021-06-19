CC = g++

arr : main.o array.o rangearray.o
	g++ -o arr main.o array.o rangearray.o

array.o : array.cpp
	g++ -c -g array.cpp

rangearray.o : rangearray.cpp
	g++ -c -g rangearray.cpp

.PHONY : clean
clean :
	rm *.o arr
