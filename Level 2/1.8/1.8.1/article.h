// article.h
#ifndef PRINT_H
#define PRINT_H

#include<stdio.h>

/**
 * @brief An article
*/
struct Article
{
	/**
	 * @brief The article number
	*/
	int articleNum;
	
	/**
	 * @brief The article quantity
	*/
	int qty;

	/**
	 * @brief Article's description
	*/
	char descripn[20];
};

/**
 * @brief Prints info about an article
 * @param Pointer to struct Article 
*/
void Print(struct Article*);

#endif // !PRINT_H
