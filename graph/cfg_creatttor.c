/*
	This file contains functions for gotoing out the AST
	in addition the symbol table is created during parsing

	For the purpose of parsing, recursive functions are declared for each struct type
	If structs are nested, the the functions call the specific function for the next struct
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "cfg_creatttor.h"

extern struct PROGRAM *root;

FILE* cfgStream;

/*
	Generates the AST text representation and the symbol table
	For both files seperate streams are needed - their opening/closing should be handled from the outside
*/
void generateCFG(FILE *cfgStreamPar)
{
	cfgStream = cfgStreamPar;

	struct FUNCTION *currentFunc = root->FuncList;

	while (currentFunc != NULL)
	{
		fprintf(cfgStream, "%s\n", currentFunc->ID);
		gotoFunction(currentFunc);
		currentFunc = currentFunc->prev;
	}
}

void gotoDeclaration(struct DECLARATION* decl)
{
	struct IDENTIFIER *currIdent = decl->ilist;

	while (currIdent != NULL)
	{
		gotoIdentifier(currIdent);
		currIdent = currIdent->prev;
	}
}

void gotoFunction(struct FUNCTION *func)
{
	struct PARAMETER *currPar = func->ParamList;

	while (currPar != NULL)
	{
		gotoParameter(currPar);
		currPar = currPar->prev;
	}

	gotoCompound(func->CStmt);

}

void gotoParameter(struct PARAMETER *par)
{
	gotoIdentifier(par->id);	
}

void gotoCompound(struct COMPOUNDSTMT *comp)
{
	struct DECLARATION *currDecl = comp->DeclList;

	while (currDecl != NULL)
	{
		gotoDeclaration(currDecl);
		currDecl = currDecl->prev;
	}

	struct STMT *currStmt = comp->StmtList;

	while (currStmt != NULL)
	{
		gotoStatement(currStmt, 0);
		currStmt = currStmt->prev;
	}
}

void gotoStatement(struct STMT *stmt, int isAlreadyDeeper)
{
	/* statement needs to be switched, because multiple possibilities are available */
	switch (stmt->e_stmt)
	{
		case eAssign:
			gotoAssign(stmt->stmt.assign_s);
			break;
		case eCall:
			gotoCall(stmt->stmt.call_s);
			break;
		case eRet:
			gotoExpr(stmt->stmt.return_s);
			break;
		case eWhile:
			gotoWhile(stmt->stmt.while_s);
			break;
		case eDoWhile:
			gotoDoWhile(stmt->stmt.dowhile_s);
			break;
		case eFor:
			gotoFor(stmt->stmt.for_s);
			break;
		case eIf:
			gotoIf(stmt->stmt.if_s);
			break;
		case eCompound:
			gotoCompound(stmt->stmt.compound_s);
			break;
		case eSemi:
			break;
	}
}

void gotoExpr(struct EXPR *expr)
{
	/* expressions need to be switched, because multiple possibilities are available */
	switch(expr->e_expr)
	{
		case eUnop:
			gotoUnop(expr->expression.unop_expr);
			break;
		case eBinop:
			gotoBinop(expr->expression.binop_expr);
			break;
		case eCallExpr:
			gotoCall(expr->expression.call_expr);
			break;
		case eIntnum:
			gotoInt(expr->expression.intnum);
			break;
		case eFloatnum:
			gotoFloat(expr->expression.floatnum);
			break;
		case eId:
			gotoIDs(expr->expression.ID_expr);
			break;
		case eExpr:
			gotoExpr(expr->expression.bracket);
			break;
	}
}

void gotoUnop(struct UNOP *un)
{
	gotoExpr(un->expr);
}

void gotoBinop(struct BINOP *bin)
{
	gotoExpr(bin->expr1);
	gotoExpr(bin->expr2);
}

void gotoIDs(struct IDs *ids)
{
	if (ids->expr != NULL)
	{
		gotoExpr(ids->expr);
	}
}

void gotoArgument(struct ARGLIST *arg)
{
	gotoExpr(arg->expr);
}

void gotoAssign(struct ASSIGN *assign)
{
	if (assign->index != NULL)
	{
		gotoExpr(assign->index);
	}

	gotoExpr(assign->expr);
}

void gotoCall(struct CALL *call)
{
	struct ARGLIST *currArg = call->arg;

	while (currArg != NULL)
	{
		gotoArgument(currArg);
		currArg = currArg->prev;
	}
}

void gotoWhile(struct WHILEs *whil)
{
	gotoExpr(whil->condition);
	gotoStatement(whil->stmt, 1);
}

void gotoDoWhile(struct DOWHILEs *dowhile)
{
	gotoStatement(dowhile->stmt, 1);
	gotoExpr(dowhile->condition);
}

void gotoFor(struct FORs *fr)
{
	gotoAssign(fr->init);
	gotoExpr(fr->condition);
	gotoAssign(fr->next);
	gotoStatement(fr->stmt, 1);
}

void gotoIf(struct IFs *iff)
{
	gotoExpr(iff->condition);
	gotoStatement(iff->if_s, 1);

	if (iff->else_s != NULL)
	{	
		gotoStatement(iff->else_s, 1);
	}
}

void gotoIdentifier(struct IDENTIFIER* identifier)
{	
}

/*
	Helper functions, to convert enum entries to strings
*/

char* getTypeString(Typee type)
{
	/* only int and float at the moment */
	return type == eInt ? "int" : "float";
}

char* getUnopString(Unop unop)
{
	/* only '-' at the moment */
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
