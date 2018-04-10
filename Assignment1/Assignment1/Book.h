#ifndef BOOK_HEADER_H
#define BOOK_HEADER_H

#include<string>
using std::string;

enum BookType
{
	History,
	SciFi,
	Cooking,
	NonFiction
};

struct Book
{
	BookType m_type;
	string m_author;
	string m_title;
};

struct SciFiBook : public Book
{
	SciFiBook(string author, string title)
		: Book{ BookType::SciFi, author, title } {}
};

struct CookingBook : public Book
{
	CookingBook(string author, string title)
		: Book{ BookType::Cooking, author, title } {}
};

struct HistoryBook : public Book
{
	HistoryBook(string author, string title)
		: Book{ BookType::History, author, title } {}
};

struct NonFictionBook : public Book
{
	NonFictionBook(string author, string title)
		: Book{ BookType::NonFiction, author, title } {}
};

#endif // !BOOK_HEADER_H