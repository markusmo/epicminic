CC = gcc
FL = flex
BI = bison
CCFLAGS = -I.
OBJ = epic_bison.tab.o lex.yy.o main.o

%.o:%.c

epicFrontEnd: $(OBJ) -lfl
$(CC) -o $@ $(OBJ) -lfl

$(OBJ):
$(CC) -c $*.c $(CCFLAGS)

lex.yy.c: flex.l
$(FL) -t $<

epic_bison.tab.c: epic_bison.y
$(BI) -d $<

clean:
rm *.o
