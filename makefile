CC = gcc
FL = flex
BI = bison
OBJ = epic_bison.tab.o lex.yy.o main.o

%.o:%.c

epicFrontEnd: $(OBJ) -lfl
	$(CC) -o $@ $(OBJ) -lfl

$(OBJ):
	$(CC) -c $*.c

epic_bison.tab.c: epic_bison.y
	$(BI) -d $<

lex.yy.c: flex.l
	$(FL) -t $<

clean:
	rm -f *.o
