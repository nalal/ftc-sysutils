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
 * 	USECASE:
 * 		Intended to be used for counting directories in a directory
 * 
 * 	EXTERNAL DEPENDANCIES:
 * 		This application is dependant on the 'lsp' application
 *======================================================================
 */

namespace fs = std::experimental::filesystem;

using std::string;

int main(uint8_t argc, char* argv[])
{
	bool cleanOut = false;
	bool recursive = false;
	bool show_hidden = false;
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
		else if(strcmp(argv[i], "-a") == 0)
		{
			show_hidden = true;
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
					if(show_hidden || p.path().filename().c_str()[0] != '.')
					{
						files++;
						dirs = 
							dirs + 
							"\n  " + 
							p.path().filename().c_str();
					}
				}
			}
		}
		else
		{
			for(auto& p: fs::directory_iterator(dir))
			{
				if(is_directory(p))
				{
					if(show_hidden || p.path().filename().c_str()[0] != '.')
					{
						files++;
						dirs = 
							dirs + 
							"\n  " + 
							p.path().filename().c_str();
					}
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
		system("lsp");
		std::cout << 
			"DIRs: " << 
			dirs << 
			"\n    Total: "<< 
			files << 
			"\n";
	}
	return 0;
}
