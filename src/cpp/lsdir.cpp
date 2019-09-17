// C++ includes
#include <iostream>
#include <experimental/filesystem>

// C includes
#include <stdint.h>
#include <string.h>

/*
 *======================================================================
 *	NAME: 
 * 		lsdir (List DIR)
 * 
 * 	AUTHOR:
 * 		Nac/Nalal/Noah
 * 
 * 	Usecase:
 * 		Intended to be used for counting directories in a directory
 *======================================================================
 */

namespace fs = std::experimental::filesystem;

using std::string;

int main(uint8_t argc, char* argv[])
{
	bool cleanOut = false;
	bool recursive = false;
	string dir = "./";
	for(uint8_t i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "-s") == 0)
		{
			cleanOut = true;
		}
		else if(strcmp(argv[i], "-r") == 0)
		{
			recursive = true;
		}
		else
		{
			dir = argv[i];
		}
	}
	int files = 0;
	string dirs = "";
	if(fs::exists(dir))
	{
		
		if(recursive)
		{
			for(auto& p: fs::recursive_directory_iterator(dir))
			{
				if(is_directory(p))
				{
					files++;
					dirs = 
						dirs + 
						"\n  " + 
						p.path().relative_path().c_str();
				}
			}
		}
		else
		{
			for(auto& p: fs::directory_iterator(dir))
			{
				if(is_directory(p))
				{
					files++;
					dirs = 
						dirs + 
						"\n  " + 
						p.path().relative_path().c_str();
				}
			}
		}
	}
	else
	{
		std::cout << "Directory does not exist.\n";
		return 0;
	}
	if(cleanOut)
	{
		std::cout << dirs << "\n";
	}
	else
	{
		std::cout << 
			"DIRs: " << 
			dirs << 
			"\n    Total: "<< 
			files << 
			"\n";
	}
	return 0;
}
