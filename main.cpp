// TODO: make a search system by name and genre/type. im probably not gonna make a gui myself (but feel free to make it yourself!).

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <random>
#include "Book.hpp"

std::vector<Book> books;
char splitChar = '^';

std::string askInput(std::string question)
{
	std::cout << question << "\n";
	std::string ans;
	getline(std::cin, ans);
	return ans;
}

int getRandomId()
{
	int maxRandNum = 100000;
	int num = rand() % maxRandNum;

	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].id == num)
		{
			num = getRandomId();
		}
	}

	return num;
}

void loadBooks()
{
	std::fstream booksFile;
	booksFile.open("books.txt");
	for (std::string line; getline(booksFile, line);)
	{
		std::stringstream ssin(line);
		std::string name, id, author, pages, type;
		int i = 0;
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

void writeBookFile()
{
	std::string bookMsg = books[0].name + splitChar + std::to_string(books[0].id) + splitChar + books[0].author + splitChar + std::to_string(books[0].pages) + splitChar + books[0].type;
	std::ofstream booksFile("books.txt");
	booksFile << bookMsg;
	booksFile.close();

	std::ofstream booksFileAdditive("books.txt", std::fstream::app);
	for (int i = 1; i < books.size(); i++)
	{
		bookMsg = "\n" + books[i].name + splitChar + std::to_string(books[i].id) + splitChar + books[i].author + splitChar + std::to_string(books[i].pages) + splitChar + books[i].type;
		booksFileAdditive << bookMsg;
	}
	booksFileAdditive.close();
	loadBooks();
}

void createBook()
{
	std::string name, id, author, pages, type, writeString;
	
	name = askInput("What is the Name of the book you want to add?");
	id = std::to_string(getRandomId());
	author = askInput("What is the Author of the book you want to add?");
	pages = askInput("What is the number of Pages of the book you want to add?");
	type = askInput("What are the genres of the book you want to add? (e.g.: Science-Fiction, Novel)");

	writeString = "\n" + name + splitChar + id + splitChar + author + splitChar + pages + splitChar + type;
	std::ofstream booksFile("books.txt", std::fstream::app);
	booksFile << writeString;
	booksFile.close();

	loadBooks();
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

void randomizeIds()
{
	for (int i = 0; i < books.size(); i++)
	{
		books[i].id = getRandomId();
	}
}

int main()
{
    srand(time(nullptr));
	loadBooks();
	// randomizeIds();
	writeBookFile();
	listAllBooks();
	// createBook();
	// listAllBooks();

	return 0;
}