// C++ includes
#include <iostream>
#include <experimental/filesystem>

// C includes
#include <stdint.h>
#include <string.h>

/*
 *======================================================================
 *	NAME: 
 * 		fcount (File Count)
 * 
 * 	AUTHOR:
 * 		Nac/Nalal/Noah
 * 
 * 	Usecase:
 * 		Intended to be used for counting files in a directory
 *======================================================================
 */

namespace fs = std::experimental::filesystem;

int main(uint8_t argc, char* argv[])
{
	bool cleanOut = false;
	char* dir;
	for(uint8_t i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "-s") == 0)
		{
			cleanOut = true;
		}
		else if(strcmp(argv[i], "-t") == 0)
		{
			dir = argv[i+1];
		}
	}
	int files = 0;
	for(auto& p: fs::directory_iterator("./"))
	{
		files++;
	}
	if(cleanOut)
	{
		std::cout << files << "\n";
	}
	else
	{
		std::cout << "Total files: " << files << "\n";
	}
	return 0;
}
