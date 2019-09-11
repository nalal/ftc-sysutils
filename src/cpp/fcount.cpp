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
	bool validDIR = false;
	bool recursive = false;
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
			validDIR = true;
		}
		else if(strcmp(argv[i], "-r") == 0)
		{
			recursive = true;
		}
	}
	int files = 0;
	if(validDIR && fs::exists(dir))
	{
		if(recursive)
		{
			for(auto& p: fs::recursive_directory_iterator(dir))
			{
				files++;
			}
		}
		else
		{
			for(auto& p: fs::directory_iterator(dir))
			{
				files++;
			}
		}
	}
	else
	{
		std::cout << "No directory given.\n";
		return 0;
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
