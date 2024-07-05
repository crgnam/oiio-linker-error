#include <string>
#include <iostream>

#include "mylib/mylib.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2) {
		const std::string& filepath = argv[1];
		mylib::getImageDimensions(filepath);

		return 0;
	}
	else {
		const std::string& filepath = "data/example.jpg";
		mylib::getImageDimensions(filepath);
	};
};