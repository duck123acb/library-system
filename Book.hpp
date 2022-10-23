#include <iostream>
#include <string>

class Book
{
public:
	std::string title, genre, author;
	int id, pages;

	Book(std::string aTitle, int aId, std::string aAuthor, int aPages, std::string aGenre)
	{
		title = aTitle;
		id = aId;
		author = aAuthor;
		pages = aPages;
		genre = aGenre;
	}

	std::string getProperties()
	{
		return title + " || " + std::to_string(id) + " || " + author + " || " + std::to_string(pages) + " || " + genre;
	}
};