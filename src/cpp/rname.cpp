#include "rname.h"

namespace fs = std::experimental::filesystem;
using std::string;

/*======================================================================
 * NAME:
 * 		rname (ReName)
 * AUTHOR:
 * 		Nac/Nalal/Noah
 * USECASE:
 * 		Intended to let a user rename a file without using mv and 
 * 	entering the directory to the file twice
 *======================================================================
 */


//Create the new name for the file
//[path] = original path of file
//[name] = name to change to
string get_name(char * path, char * name)
{
	string s_path = path;
	string s_name = name;
	//If the file is not in a subdirectory, return name
	switch(s_path.find("/"))
	{
		case string::npos:
			return s_name;
	}
	std::size_t found = s_path.find_last_of("/");
	string new_path = s_path.substr(0,found) + s_name;
	return new_path;
}

//Print help string
void print_help()
{
	printf("Usage: 'rname <Rename Target> <New Name>'\n");
}

int main(int argc, char * argv[])
{
	for(int i = 1; i < argc; i++)
	{
		switch(strcmp(argv[i],"-h"))
		{
			case 0:
				print_help();
				return 0;
		}
	}
	//Verify that the correct arguments were provided
	switch(argc)
	{
		//If nothing is provided, argc will be 1
		case 1:
			printf("File not provided\n");
			print_help();
			return 0;
		//If only file path is provided, argc will be 2
		case 2:
			printf("New name not provided\n");
			print_help();
			return 0;
	}
	//Verify that the file exists
	switch(fs::exists(argv[1]))
	{
		case false:
			printf("File '%s' not found\n", argv[1]);
			return 0;
	}
	string new_name = get_name(argv[1], argv[2]);
	char command[2550];
	sprintf(command, "mv %s %s", argv[1], new_name.c_str());
	system(command);
	return 0;
}
