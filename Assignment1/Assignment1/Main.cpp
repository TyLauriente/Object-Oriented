#include<iostream>
#include"Array.h"
#include"Book.h"
#include"Inventory.h"
#include<string>

using namespace std;

int option(string question, string options[], int amount)
{
	int answer;
	//Ask Question and print options
	cout << question << endl;
	for (int index = 0; index < amount; ++index)
		cout << index <<". " << options[index] << endl;
	cout << "> ";

	cin >> answer;

	//Ask again until answer are from 0 - amount
	while (answer < 0 || answer > amount-1)
	{
		system("cls");
		cout << "Please enter a value from 0-" << amount - 1 << endl;
		cout << question << endl;
		for (int index = 0; index < amount; ++index)
			cout << index << ". " << options[index] << endl;
		cout << "> ";
		cin >> answer;
	}
	return answer;
}

void printBooks(BookType bookType)
{
	Inventory inventory;
	Array<Book>* books = inventory.getBooksOfType(bookType);

	for (int index = 0; index < inventory.getAmountOfGenre(bookType); ++index)
	{
		cout << "Book " << index + 1 << endl;
		cout << "Title: " << books->GetItem(index).m_title << endl;
		cout << "Author: " << books->GetItem(index).m_author << endl << endl;
	}
}

int main()
{
	int answer;
	do
	{
		system("cls");
		answer = option("What kind of books would you like to see?", new string[4]{ "History", "SciFi", "Cooking", "NonFiction" }, 4);
		system("cls");
		if (answer == 0)
			printBooks(BookType::History);
		else if (answer == 1)
			printBooks(BookType::SciFi);
		else if( answer == 2)
			printBooks(BookType::Cooking);
		else
			printBooks(BookType::NonFiction);
	} while (option("Would you like to run again?", new string[2] { "Yes","No" }, 2) != 1);
}