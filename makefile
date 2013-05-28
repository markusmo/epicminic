CC = gcc
BI = bison -d -r all --verbose
FL = flex
OBJ = main.o epic_bison.tab.o lex.yy.o printer.o symbolTable.o cfg_creatttor.o
HEADERS = epic_bison.tab.h printer.h symbolTable.h cfg_creatttor.h graph/graph.h graph/block.h

all: epic_bison.tab.h epic_parser clean

epic_parser: $(OBJ)
	$(CC) -o $@ $(OBJ) -lfl

epic_bison.tab.c: epic_bison.y
	$(BI) epic_bison.y

epic_bison.tab.h: epic_bison.y
	$(BI) epic_bison.y

%.o: %.c $(HEADERS)
	$(CC) -c $<

lex.yy.c: flex.l
	$(FL) -l $<

lex.yy.o: lex.yy.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) *.tab.c *.tab.h *.yy.c *.output
