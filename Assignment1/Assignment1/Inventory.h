#ifndef INVENTORY_HEADER_H
#define INVENTORY_HEADER_H
#include"Array.h"
#include"Book.h"
class Inventory
{
public:
	Inventory();

	Array<Book>* getBooksOfType(BookType type);

private:
	Array<Book>* m_inventory;
};

Inventory::Inventory()
{
	m_inventory = new Array<Book>(2);
	m_inventory->setItem(0, CookingBook("SomeGuy", "How to cook stuff"));
	m_inventory->setItem(1, SciFiBook("SomeOtherGuy", "How to build telescopes"));
}

Array<Book>* Inventory::getBooksOfType(BookType type)
{
	int numBooksFound = 0;
	for (int index = 0; index < m_inventory->getSize(); ++index)
	{
		if (m_inventory[index].GetItem(index).m_type == type)
		{
			numBooksFound++;
		}
	}

	// TODO - what if you dont find any?

	Array<Book>* booksFound = new Array<Book>(numBooksFound);
	int insertIndex = 0;
	for (int index = 0; index < m_inventory->getSize(); ++index)
	{
		if (m_inventory[index].GetItem(index).m_type == type)
		{
			booksFound->setItem(insertIndex, m_inventory->GetItem(index));
			insertIndex++;
		}
	}

	return booksFound;
}

#endif // !INVENTORY_HEADER_H
