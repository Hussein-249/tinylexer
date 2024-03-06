c_compiler: main.o token.o
	gcc -o c_compiler main.o token.o

main.o: main.c token.h
	gcc -c main.c

token.o: token.c token.h
	gcc -c token.c

clean:
	rm -f *.o c_compiler
