OPT = -Wall -g
INCLUDES = -Iheader

c_compiler: main.o token.o lexer.o
	gcc $(OPT) $(INCLUDES) -o c_compiler main.o token.o lexer.o

main.o: main.c header/token.h
	gcc $(OPT) $(INCLUDES) -c main.c

lexer.o: lexer.c header/lexer.h header/token.h
	gcc $(OPT) $(INCLUDES) -c lexer.c

token.o: token.c header/token.h
	gcc $(OPT) $(INCLUDES) -c token.c

clean:
	rm -f *.o c_compiler
