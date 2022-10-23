#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <random>
#include "Book.hpp"

// global vars
std::vector<Book> books;
char splitChar = '^';

// INPUT FUNCTIONS
std::string askInput(std::string question)
{
	std::cout << question << "\n";
	std::string ans;
	getline(std::cin, ans);
	return ans;
}


// ID FUNCTIONS
int getRandomId()
{
	int maxRandNum = 100000;
	int num = rand() % maxRandNum;

	for (int i = 0; i < books.size(); i++) // make sure that the id is unique
	{
		if (books[i].id == num)
		{
			num = getRandomId();
		}
	}

	return num;
}

void randomizeAllIds()
{
	for (int i = 0; i < books.size(); i++)
	{
		books[i].id = getRandomId();
	}
}


// BOOK FILE MANAGEMENT
void loadBooks()
{
	std::fstream booksFile;
	booksFile.open("books.txt");
	for (std::string line; getline(booksFile, line);)
	{
		std::stringstream ssin(line);
		std::string title, id, author, pages, genre;
		int i = 0;
		for (std::string segment; std::getline(ssin, segment, '^');)
		{
			switch (i)
			{
			case 0:
				title = segment;
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
				genre = segment;
				break;
			
			default:
				break;
			}

			i++;
		}

		books.push_back(Book(title, std::stoi(id), author, std::stoi(pages), genre));
	}
	booksFile.close();
}

void writeBookFile()
{
	std::string bookMsg = books[0].title + splitChar + std::to_string(books[0].id) + splitChar + books[0].author + splitChar + std::to_string(books[0].pages) + splitChar + books[0].genre;
	std::ofstream booksFile("books.txt");
	booksFile << bookMsg;
	booksFile.close();

	std::ofstream booksFileAdditive("books.txt", std::fstream::app);
	for (int i = 1; i < books.size(); i++)
	{
		bookMsg = "\n" + books[i].title + splitChar + std::to_string(books[i].id) + splitChar + books[i].author + splitChar + std::to_string(books[i].pages) + splitChar + books[i].genre;
		booksFileAdditive << bookMsg;
	}
	booksFileAdditive.close();
	loadBooks();
}

void createBook()
{
	std::string title, id, author, pages, genre, writeString;
	
	title = askInput("What is the Title of the book you want to add?");
	id = std::to_string(getRandomId());
	author = askInput("What is the Author of the book you want to add?");
	pages = askInput("What is the Number of Pages of the book you want to add?");
	genre = askInput("What are the Genres of the book you want to add? (e.g.: Science-Fiction, Novel)");

	writeString = "\n" + title + splitChar + id + splitChar + author + splitChar + pages + splitChar + genre;
	std::ofstream booksFile("books.txt", std::fstream::app);
	booksFile << writeString;
	booksFile.close();

	loadBooks();
}


// PRINTING BOOKS TO CONSOLE FUNCTIONS
void listAllBooks()
{
	for (int i = 0; i < books.size(); i++)
	{
		std::cout << books[i].getProperties() << "\n";
	}
}

void getSpecificBookFromList(int i)
{
	std::cout << books[i].getProperties() << "\n";
}


// SEARCHING FUNCTIONS
void searchBookTitle(std::string search)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].title.find(search) != std::string::npos) std::cout << books[i].getProperties() << "\n";
		else std::cout << "No books found with that Title\n";
	}
}

void searchBookAuthor(std::string search)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].author.find(search) != std::string::npos) std::cout << books[i].getProperties() << "\n";
		else std::cout << "No books found with that Author\n";
	}
}

void searchBookGenre(std::string search)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].genre.find(search) != std::string::npos) std::cout << books[i].getProperties() << "\n";
		else std::cout << "No books found with that/those Genre\n";
	}
}


int main()
{
    srand(time(nullptr));

	/**
	 * MAIN FUNCTIONS
	 * loadBooks();
	 * randomizeAllIds();
	 * writeBookFile();
	 * createBook();
	 * searchBookTitle("Dan");
	 * searchBookAuthor("Lo");
	 * searchBookGenre("Novel");
	 * getSpecificBookFromList(books.size() - 1);
	 * listAllBooks();
	**/
	


	return 0;
}