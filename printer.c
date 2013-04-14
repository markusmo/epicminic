#include "printer.h"

extern struct PROGRAM *root;

void asdf(FILE *stream)
{
	if (root->DeclList != NULL)
	{
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
	}
}

void printFunction(struct FUNCTION *func)
{
	printf("IDENTIFIER, Type: %d, ID: %s \n", (int)func->t, func->ID);
	struct PARAMETER *currPar = func->ParamList;

	while (currPar != NULL)
	{
		printParameter(currPar);
		currPar = currPar->prev;
	} 

	printCompound(func->CStmt);
}

void printParameter(struct PARAMETER *par)
{
	printf("PARAMETER, type: %d \n", (int)par->t);
	printIdentifier(par->id);
}

void printCompound(struct COMPOUNDSTMT *comp)
{
	printf("COMPOUND \n");
	struct DECLARATION *currDecl = comp->DeclList;

	while (currDecl != NULL)
	{
		printDeclaration(currDecl);
		currDecl = currDecl->prev;
	}

	struct STMT *currStmt = comp->StmtList;

	while (currStmt != NULL)
	{
		printStatement(currStmt);
		currStmt = currStmt->prev;
	}
}

void printStatement(struct STMT *stmt)
{
	printf("STATEMENT, type: %d \n", (int)stmt->e_stmt);

	switch (stmt->e_stmt)
	{
		case eAssign:
			printAssign(stmt->stmt.assign_s);
			break;
		case eCall:
			printCall(stmt->stmt.call_s);
			break;
		case eRet:
			printExpr(stmt->stmt.return_s);
			break;
		case eWhile:
			printWhile(stmt->stmt.while_s);
			break;
		case eFor:
			printFor(stmt->stmt.for_s);
			break;
		case eIf:
			printIf(stmt->stmt.if_s);
			break;
		case eCompound:
			printCompound(stmt->stmt.compound_s);
			break;
		case eSemi:
			break;
	}
}

void printExpr(struct EXPR *expr)
{
	printf("EXPRESSION \n");
	
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
			printExpr(expr->expression.bracket);
			break;
	}
}

void printInt(int i)
{
	printf("INT %d\n", i);
}

void printFloat(float f)
{
	printf("FLOAT %f\n", f);
}

void printUnop(struct UNOP *un)
{
	printf("UNOP, operator: %d \n", (int)un->u);
	printExpr(un->expr);
}

void printBinop(struct BINOP *bin)
{
	printf("BINOP, operator: %d  \n", (int)bin->bi);
	printExpr(bin->expr1);
	printExpr(bin->expr2);
}

void printIDs(struct IDs *ids)
{
	printf("IDs, ID: %s\n", ids->ID);
	if (ids->expr != NULL)
	{
		printf("ARRAY \n");
		printExpr(ids->expr);
	}
}

void printArgument(struct ARGLIST *arg)
{
	printf("ARGUMENT \n");
	printExpr(arg->expr);
}

void printAssign(struct ASSIGN *assign)
{
	printf("ASSIGN ID: %s \n", assign->ID);
	if (assign->index != NULL)
	{
		printf("ARRAY \n");
		printExpr(assign->index);
	}
	printExpr(assign->expr);
}

void printCall(struct CALL *call)
{
	printf("CALL ID \n", call->ID);
	struct ARGLIST *currArg = call->arg;
	while (currArg != NULL)
	{
		printArgument(currArg);
		currArg = currArg->prev;
	}
}

void printWhile(struct WHILEs *whil)
{
	printf("WHILE \n");
	printExpr(whil->condition);
	printStatement(whil->stmt);
}

void printFor(struct FORs *fr)
{
	printf("FOR \n");
	printAssign(fr->init);
	printExpr(fr->condition);
	printAssign(fr->next);
	printStatement(fr->stmt);
}

void printIf(struct IFs *iff)
{
	printf("IF \n");
	printExpr(iff->condition);
	printStatement(iff->if_s);
	if (iff->else_s != NULL)
	{
		printf("ELSE \n");
		printStatement(iff->else_s);
	}
}

void printDeclaration(struct DECLARATION* decl)
{
	printf("DECLARATION, type: %d \n", (int)decl->t);
	struct IDENTIFIER *currIdent = decl->ilist;

	while (currIdent != NULL)
	{
		printIdentifier(currIdent);
		currIdent = currIdent->prev;
	} 
}

void printIdentifier(struct IDENTIFIER* identifier)
{
	printf("IDENTIFIER, ID: %s, num: %d \n", identifier->ID, identifier->intnum);
}

void printSymbolTable(FILE *stream)
{

}
