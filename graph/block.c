#include "block.h"

static blockCounter = 0;

Block createBlock()
{
	Block b;
	b.nr = blockCounter++;
	return b;
}
