#ifndef INVENTORY_HEADER_H
#define INVENTORY_HEADER_H
#include"Array.h"
#include"Book.h"

const int AMOUNT_OF_BOOKS_INVENTORY = 8;

class Inventory
{
public:
	Inventory();

	int getAmountOfGenre(BookType book) const;

	Array<Book>* getBooksOfType(BookType type) const;

private:
	Array<Book>* m_inventory;
};

#endif // !INVENTORY_HEADER_H
