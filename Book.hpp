#include <iostream>
#include <string>

class Book
{
public:
	std::string name, type, author;
	int id, pages;

	Book(std::string aName, int aId, std::string aAuthor, int aPages, std::string atype)
	{
		name = aName;
		id = aId;
		author = aAuthor;
		pages = aPages;
		type = atype;
	}

	std::string getProperties()
	{
		return name + " " + std::to_string(id) + " " + author + " " + std::to_string(pages) + " " + type;
	}
};