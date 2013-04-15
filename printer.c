#include "printer.h"

extern struct PROGRAM *root;

FILE *astStream;
SymbolTable* table;

void asdf(FILE *stream)
{
	astStream = stream;
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
}

void printDeclaration(struct DECLARATION* decl)
{
	printf("DECLARATION, type: %d \n", (int)decl->t);
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
	printf("IDENTIFIER, Type: %d, ID: %s \n", (int)func->t, func->ID);

	fprintf(astStream, "%s %s(", getTypeString(func->t), func->ID);

	struct PARAMETER *currPar = func->ParamList;

	while (currPar != NULL)
	{
		printParameter(currPar);
		currPar = currPar->prev;
	}

	fprintf(astStream, ")\n");

	printCompound(func->CStmt);
}

void printParameter(struct PARAMETER *par)
{
	printf("PARAMETER, type: %d \n", (int)par->t);
	fprintf(astStream, "%s ", getTypeString(par->t));
	printIdentifier(par->id);
	fprintf(astStream, ", ");
}

void printCompound(struct COMPOUNDSTMT *comp)
{
	printf("COMPOUND \n");
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
		printStatement(currStmt);
		currStmt = currStmt->prev;
	}

	fprintf(astStream, "}\n");
}

void printStatement(struct STMT *stmt)
{
	printf("STATEMENT, type: %d \n", (int)stmt->e_stmt);

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
			printCompound(stmt->stmt.compound_s);
			break;
		case eSemi:
			fprintf(astStream, ";\n");
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
			fprintf(astStream, "(");
			printExpr(expr->expression.bracket);
			fprintf(astStream, ")");
			break;
	}
}

void printInt(int i)
{
	printf("INT %d\n", i);
	fprintf(astStream, "%d", i);
}

void printFloat(float f)
{
	printf("FLOAT %f\n", f);
	fprintf(astStream, "%f", f);
}

void printUnop(struct UNOP *un)
{
	printf("UNOP, operator: %d \n", (int)un->u);
	fprintf(astStream, "%s", getUnopString(un->u));
	printExpr(un->expr);
}

void printBinop(struct BINOP *bin)
{
	printf("BINOP, operator: %d  \n", (int)bin->bi);
	printExpr(bin->expr1);
	fprintf(astStream, "%s", getBinopString(bin->bi));
	printExpr(bin->expr2);
}

void printIDs(struct IDs *ids)
{
	printf("IDs, ID: %s\n", ids->ID);
	fprintf(astStream, "%s", ids->ID);

	if (ids->expr != NULL)
	{
		printf("ARRAY \n");
		fprintf(astStream, "[");
		printExpr(ids->expr);
		fprintf(astStream, "]");
	}
	fprintf(astStream, " ");
}

void printArgument(struct ARGLIST *arg)
{
	printf("ARGUMENT \n");
	printExpr(arg->expr);
	fprintf(astStream, ", ");
}

void printAssign(struct ASSIGN *assign)
{
	printf("ASSIGN ID: %s \n", assign->ID);
	fprintf(astStream, "%s", assign->ID);
	if (assign->index != NULL)
	{
		fprintf(astStream, "[");
		printf("ARRAY \n");
		printExpr(assign->index);
		fprintf(astStream, "]");
	}
	fprintf(astStream, "=");
	printExpr(assign->expr);
}

void printCall(struct CALL *call)
{
	printf("CALL ID \n", call->ID);
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
	printf("WHILE \n");
	fprintf(astStream, "while(");
	printExpr(whil->condition);
	fprintf(astStream, ")\n");
	printStatement(whil->stmt);
}

void printDoWhile(struct DOWHILEs *dowhile)
{
	printf("DO WHILE \n");
	fprintf(astStream, "do\n");
	printStatement(dowhile->stmt);
	fprintf(astStream, "while(");
	printExpr(dowhile->condition);
	fprintf(astStream, ");\n");
}

void printFor(struct FORs *fr)
{
	printf("FOR \n");
	fprintf(astStream, "for(");
	printAssign(fr->init);
	fprintf(astStream, ";");
	printExpr(fr->condition);
	fprintf(astStream, ";");
	printAssign(fr->next);
	fprintf(astStream, ")\n");
	printStatement(fr->stmt);
}

void printIf(struct IFs *iff)
{
	printf("IF \n");
	fprintf(astStream, "if (");
	printExpr(iff->condition);
	fprintf(astStream, ")\n");

	printStatement(iff->if_s);
	if (iff->else_s != NULL)
	{
		printf("ELSE \n");
		fprintf(astStream, "else\n");
		printStatement(iff->else_s);
	}
}

void printIdentifier(struct IDENTIFIER* identifier)
{
	printf("IDENTIFIER, ID: %s, num: %d \n", identifier->ID, identifier->intnum);
	addEntry(table, identifier->ID, identifier->intnum, eVar);

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

void printSymbolTable(FILE *stream)
{

}
