#ifndef EXC_H
#define EXC_H
#include <string>
class Exception{
	private:
		int number;
		std::string message;
	public:
		Exception(int a, std::string b);
		~Exception() {};
		void show();
};
#endif
