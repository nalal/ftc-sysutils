#include "rmn.h"

/*======================================================================
 * Application Name:
 * 		rmn (Remove and NULL)
 * Use:
 * 		write null to file then remove
 * Execution:
 * 		rmn <target file>
 * Flags:
 * 		-p (preserve file after nullification)
 * 		-r (recursivelly itterate through directories)
 * Author:
 * 		Nac, Nalal, Nacalal
 *======================================================================
 */

/*	RESPONSE CODES:
 * 		1 = FILE NOT FOUND
 * 		2 = FILE IS DIRECTORY AND OP IS NON-RECURSIVE
 * 		3 = FILE COULD NOT BE OPENED
 */

//Help message
void print_help()
{
	printf("Usage:\n");
	printf("	rmn <file/folder>\n");
	printf("Arguments:\n");
	printf("	-p (preserve file after null)\n");
	printf(
		"	-r (null all files in directory and sub directories)\n"
	);
	printf("	-h (display this help message)\n");
}

//Nullify target file
//	[file_path]: relative path to file
int null_target(const char * file_path)
{
	printf("Nulling file '%s'...\n", file_path);
	struct stat st;
	//Get target file info for file size
	stat(file_path, &st);
	printf("File size: %d BYTES\n", st.st_size);
	FILE * n_file = fopen(file_path, "wb");
	//Print 8 bit unsigned int set as 0 to each byte of file
	if(n_file != NULL)
	{
		for(int i = 0; i < st.st_size; i++)
		{
			time_t t;
			srand((unsigned) time(&t));
			uint8_t null_i = (uint8_t)rand();
			fwrite(&null_i, sizeof(null_i), 1, n_file);
		}
		fclose(n_file);
		printf("File '%s' scrammed\n", file_path);
		return 0;
	}
	else
		return 1;
}

//Check if target is directory and if this is a recursive operation
//	[file_path]: relative path to file/folder
//	[preserve]: should file/folder be deleted after nullification?
//	[recurse]: if target is DIR, should we itterate through contents?
int null_file(const char * file_path, bool *preserve, bool *recurse)
{
	//Check if target exists, if not return failstate
	if(!fs::exists(file_path))
	{
		printf("File '%s' not found\n", file_path);
		return 1;
	}
	//If target is DIR, if so and not recursive, return failstate
	else if(fs::is_directory(file_path) && !*recurse)
	{
		printf("File '%s' is a directory\n", file_path);
		return 2;
	}
	//If is DIR and recursive, itterate through and null all subcontent
	else if(fs::is_directory(file_path) && *recurse)
	{
		for(auto& p: fs::recursive_directory_iterator(file_path))
		{
			int r_code;
			if(!fs::is_directory(p.path()))
				r_code = null_target(p.path().c_str());
			if(r_code != 0)
				return 3;
		}
	}
	//If is normal file, null
	else
	{
		if(null_target(file_path) != 0)
			return 3;
	}
	//If not preserving file, remove after null
	if(!*preserve)
	{
		printf("Deleting file '%s'...\n", file_path);
		fs::remove_all(file_path);
		printf("File '%s' deleted\n", file_path);
	}
	return 0;
}

int main(int argc, char * argv[])
{
	if(argc <= 1)
	{
		printf("No input given\n");
		print_help();
		return 0;
	}
	//Preserve files after nullification
	bool F_PRSV = false;
	//Recursivelly itterate through folders
	bool F_RCSV = false;
	//Is help printed?
	bool help_printed = false;
	for(int i = 1; i < argc; i++)
	{
		//Check input for flag
		switch(argv[i][0])
		{
			case '-':
				switch(argv[i][1])
				{
					//Recursive flag
					case 'r':
						F_RCSV = true;
						break;
					//Preservation of file flag
					case 'p':
						F_PRSV = true;
						break;
					//Help flag
					case 'h':
						if(!help_printed)
							print_help();
						help_printed = true;
						break;
					//Unknown flag warning
					default:
						printf("Unknown flag %s\n", argv[i]);
						if(!help_printed)
							print_help();
						help_printed = true;
				}
				break;
			//If not flag, treat as target and null
			default:
				int ret_code = null_file(argv[i], &F_PRSV, &F_RCSV);
				//If response code is no 0 (OK), print error code
				if(ret_code != 0)
				{
					printf(
						"ERROR: %s (%i)\n", 
						err_code[ret_code], 
						ret_code
					);
					return ret_code;
				}
		}
	}
	return 0;
}
