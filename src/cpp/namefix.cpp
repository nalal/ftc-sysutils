#include "namefix.h"

namespace fs = std::filesystem;
using std::thread;

bool match_char(char check_char, bool v_char_found)
{
	switch(check_char)
	{
		case '_':
			if(v_char_found == true)
				return true;
			else
				return false;
		case '/':
			return true;
		case '-':
			return true;
		case '.':
			return true;
		default:
			return false;
	}
}

bool is_valid_char(char check_char, bool v_char_found)
{
	if(isalpha(check_char) || isdigit(check_char))
	{
		//printf("isalfa\n");
		return true;
	}
	else if(match_char(check_char, v_char_found))
		return true;
	else
		return false;
}

void run_fix(char * fix_name)
{
	printf("Fixing name for '%s'.\n", fix_name);
	char file_name[2550];
	memcpy(file_name, strrchr(fix_name, '/'), 2550 * sizeof(char));
	bool valid_char_found = false;
	int f_valid_index = 0;
	for(int i = 0; file_name[i] != '\0'; i++)
	{
		if(!is_valid_char(file_name[i], valid_char_found))
			file_name[i] = '_';
		else if(!valid_char_found && i > 0)
		{
			f_valid_index = i;
			valid_char_found = true;
		}
	}
	char * v_name = file_name + f_valid_index;
	printf("%s\n", v_name);
	char cur_path[25500];
	memcpy(cur_path, fix_name, 2550 * sizeof(fix_name));
	strrchr(cur_path, '/')[0] = '\0';
	char final_name[25500];
	sprintf(final_name, "%s/%s", cur_path, v_name);
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
