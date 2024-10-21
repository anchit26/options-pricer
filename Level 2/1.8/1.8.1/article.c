#include "article.h"

// Print
void Print(struct Article* a)
{
	printf("Article Number: %d\n", a->articleNum);
	printf("Article Quantity: %d\n", a->qty);
	printf("Article Description: %s\n", a->descripn);
}
