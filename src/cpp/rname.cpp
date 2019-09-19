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
using std::cout;

int main(uint8_t argc, char* argv[])
{
	string file = "";
	string name = "";
	if(argc < 2)
	{
		cout << "Missing agruments.\n";
		return 0;
	}
	else
	{
		file = argv[0];
		name = argv[1];
	}
	if(fs::exists(file))
	{
		
	}
	return 0;
}
