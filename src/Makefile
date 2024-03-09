OPT = -Wall

c_compiler: main.o token.o
	gcc $(OPT) -o c_compiler main.o token.o

main.o: main.c token.h
	gcc $(OPT) -c main.c

lexer.o: lexer.c lexer.h Token.h
	gcc $(OPT) -c lexer.c

token.o: token.c token.h
	gcc $(OPT) -c token.c

clean:
	rm -f *.o c_compiler
