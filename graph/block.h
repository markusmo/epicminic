typedef struct Block {
	int nr;
	struct DECLARATION declarations;	
	struct STMT statements;
} Block;

Block createBlock();
