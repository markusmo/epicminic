#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "printer.h"
#include "symbolTable.h"

extern struct PROGRAM *root;

FILE *tableStream;
FILE* astStream;
SymbolTable* table;

void generateOutput(FILE *astStreamPar, FILE *tableStream)
{
	astStream = astStreamPar;
	table = initTable();

	struct DECLARATION *currentDecl = root->DeclList;

	while (currentDecl != NULL)
	{
		printDeclaration(currentDecl);
		currentDecl = currentDecl->prev;
	}

	struct FUNCTION *currentFunc = root->FuncList;

	while (currentFunc != NULL)
	{
		printFunction(currentFunc);
		currentFunc = currentFunc->prev;
	}

	printTable(table, tableStream);
}

void printDeclaration(struct DECLARATION* decl)
{
	fprintf(astStream, "%s ", getTypeString(decl->t));
	newType(table, decl->t);
	struct IDENTIFIER *currIdent = decl->ilist;

	while (currIdent != NULL)
	{
		printIdentifier(currIdent);
		currIdent = currIdent->prev;
	}

	fprintf(astStream, ";\n");
}

void printFunction(struct FUNCTION *func)
{
	goToChild(table, func->ID);

	fprintf(astStream, "%s %s(", getTypeString(func->t), func->ID);

	struct PARAMETER *currPar = func->ParamList;
	setParam(table, 1);
	while (currPar != NULL)
	{
		printParameter(currPar);
		currPar = currPar->prev;
	}
	setParam(table, 0);
	fprintf(astStream, ")\n");

	printCompound(func->CStmt);

	goToParent(table);
}

void printParameter(struct PARAMETER *par)
{
	fprintf(astStream, "%s ", getTypeString(par->t));
	printIdentifier(par->id);
	fprintf(astStream, ", ");
}

void printCompound(struct COMPOUNDSTMT *comp)
{
	fprintf(astStream, "{\n");
	struct DECLARATION *currDecl = comp->DeclList;

	while (currDecl != NULL)
	{
		printDeclaration(currDecl);
		currDecl = currDecl->prev;
	}

	struct STMT *currStmt = comp->StmtList;

	while (currStmt != NULL)
	{
		printStatement(currStmt, 0);
		currStmt = currStmt->prev;
	}

	fprintf(astStream, "}\n");
}

void printStatement(struct STMT *stmt, int isAlreadyDeeper)
{
	switch (stmt->e_stmt)
	{
		case eAssign:
			printAssign(stmt->stmt.assign_s);
			fprintf(astStream, ";\n");
			break;
		case eCall:
			printCall(stmt->stmt.call_s);
			fprintf(astStream, ";\n");
			break;
		case eRet:
			fprintf(astStream, "return ");
			printExpr(stmt->stmt.return_s);
			fprintf(astStream, ";\n");
			break;
		case eWhile:
			printWhile(stmt->stmt.while_s);
			break;
		case eDoWhile:
			printDoWhile(stmt->stmt.dowhile_s);
			break;
		case eFor:
			printFor(stmt->stmt.for_s);
			break;
		case eIf:
			printIf(stmt->stmt.if_s);
			break;
		case eCompound:
			if (!isAlreadyDeeper)
				goToChild(table, "compound");
			printCompound(stmt->stmt.compound_s);
			if (!isAlreadyDeeper)
				goToParent(table);
			break;
		case eSemi:
			fprintf(astStream, ";\n");
			break;
	}
}

void printExpr(struct EXPR *expr)
{
	switch(expr->e_expr)
	{
		case eUnop:
			printUnop(expr->expression.unop_expr);
			break;
		case eBinop:
			printBinop(expr->expression.binop_expr);
			break;
		case eCallExpr:
			printCall(expr->expression.call_expr);
			break;
		case eIntnum:
			printInt(expr->expression.intnum);
			break;
		case eFloatnum:
			printFloat(expr->expression.floatnum);
			break;
		case eId:
			printIDs(expr->expression.ID_expr);
			break;
		case eExpr:
			fprintf(astStream, "(");
			printExpr(expr->expression.bracket);
			fprintf(astStream, ")");
			break;
	}
}

void printInt(int i)
{
	fprintf(astStream, "%d", i);
}

void printFloat(float f)
{
	fprintf(astStream, "%f", f);
}

void printUnop(struct UNOP *un)
{
	fprintf(astStream, "%s", getUnopString(un->u));
	printExpr(un->expr);
}

void printBinop(struct BINOP *bin)
{
	printExpr(bin->expr1);
	fprintf(astStream, "%s", getBinopString(bin->bi));
	printExpr(bin->expr2);
}

void printIDs(struct IDs *ids)
{
	fprintf(astStream, "%s", ids->ID);

	if (ids->expr != NULL)
	{
		fprintf(astStream, "[");
		printExpr(ids->expr);
		fprintf(astStream, "]");
	}
	fprintf(astStream, " ");
}

void printArgument(struct ARGLIST *arg)
{
	printExpr(arg->expr);
	fprintf(astStream, ", ");
}

void printAssign(struct ASSIGN *assign)
{
	fprintf(astStream, "%s", assign->ID);
	if (assign->index != NULL)
	{
		fprintf(astStream, "[");
		printExpr(assign->index);
		fprintf(astStream, "]");
	}
	fprintf(astStream, "=");
	printExpr(assign->expr);
}

void printCall(struct CALL *call)
{
	fprintf(astStream, "%s(", call->ID);

	struct ARGLIST *currArg = call->arg;
	while (currArg != NULL)
	{
		printArgument(currArg);
		currArg = currArg->prev;
	}

	fprintf(astStream, ")");
}

void printWhile(struct WHILEs *whil)
{
	goToChild(table, "while");

	fprintf(astStream, "while(");
	printExpr(whil->condition);
	fprintf(astStream, ")\n");
	printStatement(whil->stmt, 1);

	goToParent(table);
}

void printDoWhile(struct DOWHILEs *dowhile)
{
	goToChild(table, "while");

	fprintf(astStream, "do\n");
	printStatement(dowhile->stmt, 1);
	fprintf(astStream, "while(");
	printExpr(dowhile->condition);
	fprintf(astStream, ");\n");

	goToParent(table);
}

void printFor(struct FORs *fr)
{
	goToChild(table, "for");

	fprintf(astStream, "for(");
	printAssign(fr->init);
	fprintf(astStream, ";");
	printExpr(fr->condition);
	fprintf(astStream, ";");
	printAssign(fr->next);
	fprintf(astStream, ")\n");
	printStatement(fr->stmt, 1);

	goToParent(table);
}

void printIf(struct IFs *iff)
{
	goToChild(table, "if");

	fprintf(astStream, "if (");
	printExpr(iff->condition);
	fprintf(astStream, ")\n");

	printStatement(iff->if_s, 1);

	goToParent(table);
	if (iff->else_s != NULL)
	{
		goToChild(table, "else");
		
		fprintf(astStream, "else\n");
		printStatement(iff->else_s, 1);

		goToParent(table);
	}
}

void printIdentifier(struct IDENTIFIER* identifier)
{
	addEntry(table, identifier->ID, identifier->intnum);

	if (identifier->intnum == 0)
		fprintf(astStream, "%s ", identifier->ID);
	else
		fprintf(astStream, "%s[%d] ", identifier->ID, identifier->intnum);
	
}

char* getTypeString(Typee type)
{
	return type == eInt ? "int" : "float";
}

char* getUnopString(Unop unop)
{
	return "-";
}

char* getBinopString(Binop binop)
{
	switch (binop)
	{
		case ePlus:
			return "+";
		case eMinus:
			return "-";
		case eMult:
			return "*";
		case eDiv:
			return "/";
		case eLT:
			return "<";
		case eGT:
			return ">";
		case eLTE:
			return "<=";
		case eGTE:
			return ">=";
		case eEQ:
			return "==";
		case eNEQ:
			return "!=";
	}
}
