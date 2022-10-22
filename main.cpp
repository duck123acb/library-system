// TODO: make a search system by name and genre/type. could maybe make an id randomiser, and im probably not gonna make a gui myself (but feel free to make it yourself!).

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Book.hpp"

std::vector<Book> books;
std::string booksFileName = "books.txt";

std::string askInput(std::string question)
{
	std::cout << question << "\n";
	std::string ans;
	getline(std::cin, ans);
	return ans;
}

int getRandomId()
{

}

void createBook()
{
	std::string name, id, author, pages, type, writeString;
	
	name = askInput("What is the Name of the book you want to add?");
	id = askInput("What is the Id of the book you want to add?");
	author = askInput("What is the Author of the book you want to add?");
	pages = askInput("What is the number of Pages of the book you want to add?");
	type = askInput("What are the genres of the book you want to add? (e.g.: Science-Fiction, Novel)");

	writeString = "\n" + name + "-" + id + "-" + author + "-" + pages + "-" + type;
	std::ofstream booksFile(booksFileName, std::fstream::app);
	booksFile << writeString;
	booksFile.close();
}

void loadBooks()
{
	std::fstream booksFile;
	booksFile.open(booksFileName);
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
	// loadBooks();

	// listAllBooks();
	// getSpecificBook(1);

	createBook();

	return 0;
}