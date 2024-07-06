#include <string>
#include <iostream>

#include "mylib.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2) {
		const std::string& filepath = argv[1];
		mylib::getImageDimensions(filepath);
		return 0;
	}
	else {
		return 1;
	};
};