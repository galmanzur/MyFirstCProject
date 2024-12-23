# This is a MakeFile written by Rotem Katzir
# To compile - run : make
# To clean object files created - run : make clean
# To run runable file after compile - run : ./abc (or other full path to shortened file)

abc: prog.o
	gcc -ansi -Wall -pedantic -g prog.o -o abc

prog.o: abc.c
	gcc -c -ansi -Wall -pedantic abc.c -o prog.o

clean:
	rm *.o
