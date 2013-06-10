#include <stdio.h>
#include <ctype.h>
#include <string.h>
#if !defined(BLOCK)
#define BLOCK
#include "block.h"
#endif
#if !defined(GRAPH)
#define GRAPH
#include "graph.h"
#endif

#include "cfg_printer.h"

FILE* cfgStream;

void setStream(FILE* stream) {
	cfgStream = stream;
}

void printCFGDeclaration(struct DECLARATION* decl)
{
	struct IDENTIFIER *currIdent = decl->ilist;
	fprintf(cfgStream, "%s ", getTypeString(decl->t));

	int first = 1;
	while (currIdent != NULL)
	{
		if (!first)
			fprintf(cfgStream, ",");

		first = 0;
		printCFGIdentifier(currIdent);
		currIdent = currIdent->prev;
	}

	fprintf(cfgStream, ";\n");
}

void printCFGFunction(struct FUNCTION *func)
{
	struct PARAMETER *currPar = func->ParamList;

	while (currPar != NULL)
	{
		printCFGParameter(currPar);
		currPar = currPar->prev;
	}

	printCFGCompound(func->CStmt);

}

void printCFGParameter(struct PARAMETER *par)
{
	printCFGIdentifier(par->id);	
}

void printCFGCompound(struct COMPOUNDSTMT *comp)
{	
	struct DECLARATION *currDecl = comp->DeclList;

	while (currDecl != NULL)
	{
		fprintf(cfgStream, "\t");
		printCFGDeclaration(currDecl);
		currDecl = currDecl->prev;
	}

	struct STMT *currStmt = comp->StmtList;	


	while (currStmt != NULL)
	{
		fprintf(cfgStream, "\t");
		printCFGStatement(currStmt);
		currStmt = currStmt->prev;
	}
}

void printCFGStatement(struct STMT *stmt)
{
	
	if(stmt == NULL)
		return;
	/* statement needs to be switched, because multiple possibilities are available */
	switch (stmt->e_stmt)
	{
		case eAssign:
			printCFGAssign(stmt->stmt.assign_s);
			fprintf(cfgStream, ";\n");
			break;
		case eCall:
			printCFGCall(stmt->stmt.call_s);
			fprintf(cfgStream, ";\n");
			break;
		case eRet:
			fprintf(cfgStream, "return ");
			printCFGExpr(stmt->stmt.return_s);
			fprintf(cfgStream, ";\n");
			break;
		case eWhile:
			printCFGWhile(stmt->stmt.while_s);
			break;
		case eDoWhile:
			printCFGDoWhile(stmt->stmt.dowhile_s);
			break;
		case eFor:
			printCFGFor(stmt->stmt.for_s);
			break;
		case eIf:
			printCFGIf(stmt->stmt.if_s);
			break;
		case eCompound:
			printCFGCompound(stmt->stmt.compound_s);
			break;
		case eSemi:
			fprintf(cfgStream, ";\n");
			break;
	}
}

void printCFGExpr(struct EXPR *expr)
{
	/* expressions need to be switched, because multiple possibilities are available */
	switch(expr->e_expr)
	{
		case eUnop:
			printCFGUnop(expr->expression.unop_expr);
			break;
		case eBinop:
			printCFGBinop(expr->expression.binop_expr);
			break;
		case eCallExpr:
			printCFGCall(expr->expression.call_expr);
			break;
		case eIntnum:
			printCFGInt(expr->expression.intnum);
			break;
		case eFloatnum:
			printCFGFloat(expr->expression.floatnum);
			break;
		case eId:
			printCFGIDs(expr->expression.ID_expr);
			break;
		case eExpr:
			fprintf(cfgStream, "(");
			printCFGExpr(expr->expression.bracket);
			fprintf(cfgStream, ")");
			break;
	}
}

void printCFGUnop(struct UNOP *un)
{
	fprintf(cfgStream, "%s", getUnopString(un->u));
	printCFGExpr(un->expr);
}

void printCFGBinop(struct BINOP *bin)
{
	printCFGExpr(bin->expr1);
	fprintf(cfgStream, "%s", getBinopString(bin->bi));
	printCFGExpr(bin->expr2);
}

void printCFGIDs(struct IDs *ids)
{
	fprintf(cfgStream, "%s", ids->ID);

	if (ids->expr != NULL)
	{
		fprintf(cfgStream, "[");
		printCFGExpr(ids->expr);
		fprintf(cfgStream, "]");
	}
}

void printCFGArgument(struct ARGLIST *arg)
{
	printCFGExpr(arg->expr);
}

void printCFGAssign(struct ASSIGN *assign)
{
	fprintf(cfgStream, "%s", assign->ID);
	if (assign->index != NULL)
	{
		fprintf(cfgStream, "[");
		printCFGExpr(assign->index);
		fprintf(cfgStream, "]");
	}

	fprintf(cfgStream, "=");
	printCFGExpr(assign->expr);
}

void printCFGCall(struct CALL *call)
{
	fprintf(cfgStream, "%s(", call->ID);
	struct ARGLIST *currArg = call->arg;
	int first = 1;

	while (currArg != NULL)
	{
		if (!first)
			fprintf(cfgStream, ", ");
		first = 0;

		printCFGArgument(currArg);
		currArg = currArg->prev;
	}

	fprintf(cfgStream, ")");
}

void printCFGWhile(struct WHILEs *whil)
{
	fprintf(cfgStream, "while(");
	printCFGExpr(whil->condition);
	fprintf(cfgStream, ")\n");

	//printCFGStatement(whil->stmt);
}

void printCFGDo(struct DOWHILEs *dowhile)
{	
	fprintf(cfgStream, "do\n");
}

void printCFGDoWhile(struct DOWHILEs *dowhile)
{	
	fprintf(cfgStream, "while(");
	printCFGExpr(dowhile->condition);
	fprintf(cfgStream, ");\n");
}

void printCFGFor(struct FORs *fr)
{
	fprintf(cfgStream, "for(");
	printCFGAssign(fr->init);
	fprintf(cfgStream, ";");
	printCFGExpr(fr->condition);
	fprintf(cfgStream, ";");
	printCFGAssign(fr->next);
	fprintf(cfgStream, ")\n");
	//printCFGStatement(fr->stmt);
}

void printCFGIf(struct IFs *iff)
{
	fprintf(cfgStream, "if (");
	printCFGExpr(iff->condition);
	fprintf(cfgStream, ")\n");

	//printCFGStatement(iff->if_s);

	//if (iff->else_s != NULL)
	//{
	//	fprintf(cfgStream, "else\n");
	//	printCFGStatement(iff->else_s);
	//}
}

void printCFGIdentifier(struct IDENTIFIER* identifier)
{	
	if (identifier->intnum == 0)
		fprintf(cfgStream, "%s", identifier->ID);
	else
		fprintf(cfgStream, "%s[%d]", identifier->ID, identifier->intnum);
}

void printCFGInt(int i)
{
	fprintf(cfgStream, "%d", i);
}

void printCFGFloat(float f)
{
	fprintf(cfgStream, "%f", f);
}

