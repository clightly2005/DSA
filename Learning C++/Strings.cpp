#include "Strings.h"
#include <string>
#include <iostream>

std::string literalString() {
	const std::string str =
		"\\n This inserts a new line:\n"
		"\\t This inserts a tab :\tlike this\n"
		"\\\" inserts a double quote : \"like this\"\n"
		"\\0 is the null terminator\n"
		"\\b This is a backspace\b\n";
	return str;
}

//local variable name is destroyed when the function ends as it only lives inside this {} - frees up memory

std::string greeting() {
	std::cout << "Please enter your full name: ";
	std::string name;//variable - object that has a name and a type
	std::cin >> name;//input operator >> - means character input

	const std::string hello = "* Hello, " + name + "! *"; //const means value wont change during its lifetime (this func)
	//build first and fifth lines of output
	const std::string first(hello.size(), '*');//member function to decide the amount of *, could be 100 or 56 or dyamic like size()
	//build second and fourth lines of output
	const std::string spaces(hello.size() - 4, ' ' ); // creates string of spaces the length of greeting for box * view
	const std::string second = "* " + spaces + " *";
	
	const std::string box = first + "\n" + second + "\n" + hello + "\n" + second + "\n" + first + "\n";
	return box;
}
