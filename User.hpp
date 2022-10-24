#include <iostream>
// name-password-tralse

class User
{
	std::string username, password;
	bool isAdmin;

	User(std::string aUsername, std::string aPassword, bool isAdmin)
	{
		username = aUsername;
		password = aPassword;
		isAdmin = isAdmin;
	}
};