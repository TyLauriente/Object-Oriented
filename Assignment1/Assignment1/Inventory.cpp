#ifndef INVENTORY_CPP
#define INVENTORY_CPP

#include"Inventory.h"

Inventory::Inventory()
{
	m_inventory = new Array<Book>(AMOUNT_OF_BOOKS_INVENTORY);
	m_inventory->setItem(0, CookingBook("Gordon Ramsey", "How to cook shit"));
	m_inventory->setItem(1, SciFiBook("E.T.", "How to go home"));
	m_inventory->setItem(2, HistoryBook("God", "How to be christian"));
	m_inventory->setItem(3, NonFictionBook("Harry Potter", "How to be a wizard"));
	m_inventory->setItem(4, CookingBook("Sir Cooks-A-Lot", "How to cook more shit"));
	m_inventory->setItem(5, SciFiBook("An Alien", "%$&#@>@<~#&$"));
	m_inventory->setItem(6, HistoryBook("Gautama Buddha", "How to meditate"));
	m_inventory->setItem(7, NonFictionBook("Lord of the rings", "Material possesions are very important"));
}

int Inventory::getAmountOfGenre(BookType type) const
{
	int numBooksFound = 0;
	for (int index = 0; index < m_inventory->getSize(); ++index)
		if (m_inventory->GetItem(index).m_type == type)
			numBooksFound++;

	return numBooksFound;
}

Array<Book>* Inventory::getBooksOfType(BookType type) const
{
	if (getAmountOfGenre(type) == 0)
		return new Array<Book>;

	Array<Book>* booksFound = new Array<Book>(getAmountOfGenre(type));
	int insertIndex = 0;
	for (int index = 0; index < m_inventory->getSize(); ++index)
	{
		if (m_inventory->GetItem(index).m_type == type)
		{
			booksFound->setItem(insertIndex, m_inventory->GetItem(index));
			insertIndex++;
		}
	}
	return booksFound;
}

#endif