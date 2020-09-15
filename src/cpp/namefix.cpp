#include "namefix.h"

namespace fs = std::filesystem;
using std::thread;

bool match_char(char check_char)
{
	switch(check_char)
	{
		case '_':
			return true;
		case '/':
			return true;
		case '.':
			return true;
		default:
			return false;
	}
}

bool is_valid_char(char check_char)
{
	if(isalpha(check_char) || isdigit(check_char))
		return true;
	else if(match_char(check_char))
		return true;
	else
		return false;
}

void run_fix(char * fix_name)
{
	printf("Fixing name for '%s'.\n", fix_name);
	char file_name[2550];
	memcpy(file_name, strrchr(fix_name, '/'), 2550 * sizeof(char));
	for(int i = 0; file_name[i] != '\0'; i++)
	{
		if(!is_valid_char(file_name[i]))
			file_name[i] = '_';
	}
	printf("%s\n", file_name);
	char cur_path[25500];
	memcpy(cur_path, fix_name, 2550 * sizeof(char));
	strrchr(cur_path, '/')[0] = '\0';
	char final_name[25500];
	sprintf(final_name, "%s%s", cur_path, file_name);
	//memmove(&file_name[0], &file_name[1], strlen(file_name));
	fs::rename(fix_name, final_name);
}


void fix_name(char * fix_name)
{
	switch(fs::exists(fix_name))
	{
		case true:
			run_fix(fix_name);
			break;
		case false:
			printf("File '%s' not found.\n", fix_name);
			break;
	}
}

int main(int argc, char * argv[])
{
	if(argc <= 1)
	{
		printf("No files selected.\n");
	}
	else
	{
		for(int i = 1; i < argc; i++)
		{
			switch(argv[i][0])
			{
				case '/':
					fix_name(argv[i]);
					break;
				default:
					char * cur_path = strdup(
						fs::current_path().c_str()
					);
					char target[25500];
					sprintf(target, "%s/%s", cur_path, argv[i]);
					fix_name(target);
					break;
			}
		}
	}
	return 0;
}
