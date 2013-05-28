typedef struct Block {
	int nr;
	struct STMT statements;
} Block;

Block createBlock();
