// C++ includes
#include <iostream>
#include <experimental/filesystem>

// C includes
#include <stdint.h>

namespace fs = std::experimental::filesystem;

int main(uint8_t argc, char* argv[])
{
	int files = 0;
	for(auto& p: fs::directory_iterator("./"))
	{
		files++;
	}
	std::cout << "Total files: " << files << "\n";
	return 0;
}
