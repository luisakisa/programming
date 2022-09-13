#include "Exc.h"
#include <iostream>
#include <string>
Exception::Exception(int a, std::string b){

	number = a;
	message = b;
}
void Exception::show()
{
		std::cout << std::endl;
		std::cout << "Error number " << number << ":" << std::endl;
		std::cout << "\t" << message << std::endl;
}