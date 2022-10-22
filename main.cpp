#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream booksFile;
	booksFile.open("books.txt");
	for (std::string line; getline(booksFile, line);)
	{
		std::cout << line << "\n";
	}
	return 0;
}