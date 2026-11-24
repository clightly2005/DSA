//standard libary headers go here.
#include <iostream>
#include "Strings.h"
//called for the program to be run. returns 0 for success and 1 for failure

int main()
{
    //output operator << 
    //output operand std::cout - means character output
	//scope operator :: - means cout is member of the std namespace
    std::cout << "Hello World!\n";

	//string content
	std::cout << literalString() << std::endl; //new line
	std::cout << greeting();

}//another kind of scope operator {}

