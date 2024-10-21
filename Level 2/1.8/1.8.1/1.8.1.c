#include "article.h"
#include <string.h>

int main()
{
	// declare an article
	struct Article article1;

	// initialize
	article1.articleNum = 5;
	article1.qty = 100;
	strcpy_s(article1.descripn, sizeof(article1.descripn), "Writing Structs");

	// print
	Print(&article1);
	return 0;
}
