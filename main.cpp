#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Book.hpp"

std::vector<Book> books;

void loadBooks()
{
	std::fstream booksFile;
	booksFile.open("books.txt");
	for (std::string line; getline(booksFile, line);)
	{
		std::stringstream ssin(line);
		std::string name, id, author, pages, type;
		int i = 0;
		char splitChar = '^';
		for (std::string segment; std::getline(ssin, segment, '^');)
		{
			switch (i)
			{
			case 0:
				name = segment;
				break;
			case 1:
				id = segment;
				break;
			case 2:
				author = segment;
				break;
			case 3:
				pages = segment;
				break;
			case 4:
				type = segment;
				break;
			
			default:
				break;
			}

			i++;
		}

		books.push_back(Book(name, std::stoi(id), author, std::stoi(pages), type));
	}
	booksFile.close();
}

void listAllBooks()
{
	for (int i = 0; i < books.size(); i++)
	{
		std::cout << books[i].getProperties() << "\n";
	}
}

void getSpecificBook(int i)
{
	std::cout << books[i].getProperties() << "\n";
}

int main()
{
	loadBooks();

	listAllBooks();
	getSpecificBook(1);

	return 0;
}