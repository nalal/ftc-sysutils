// C++ includes
#include <iostream>
#include <experimental/filesystem>

// C includes
#include <stdint.h>

/*
 *======================================================================
 *	NAME: 
 * 		lsp (List Path)
 * 
 * 	AUTHOR:
 * 		Nac/Nalal/Noah
 * 
 * 	Usecase:
 * 		Intended to be used for showing the current active path
 *======================================================================
 */

namespace fs = std::experimental::filesystem;

int main(uint8_t argc, char* argv[])
{
	std::cout << 
		"Current path: \n  " << 
		fs::current_path() << 
		"\n";
	return 0;
}
