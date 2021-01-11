// C includes
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include <thread>

//Default length of a string
const int DEF_LENGTH = 16;;
//Array of bools for exclusions
bool exclusions[126 - 36];
//Print nothing
bool silent_mode = false;
//Single thread force
bool st_mode = false;

using std::thread;

//Print help message
void print_help()
{
	printf("USAGE:\n    strgen\n");
	printf("'-e':\n    Exclude specific characters\n");
	printf("'-l':\n    String length\n");
	printf("'-t':\n    Single thread mode\n");
}

//Set characters in string as excluded
void set_exclusions(char * excluded_chars)
{
	//Get length of character array
	size_t chars = strlen(excluded_chars);
	for(int i = 0; i < chars - 1; i++)
	{
		//Set index as excluded by casting to int for index
		exclusions[(int)excluded_chars[i] - 36] = true;
	}
}

int threads_running = 0;

void generate_string(int to_generate, char* string_buff, int offset = 0)
{
	for(int i = 0; i < (to_generate + offset); i++)
	{
		//Use time as base for random seed
		time_t result = time(NULL);
		bool valid = false;
		//Seed random with current char number + time
		srand(result + i);
		int random = (rand()/65536) % (126 - 36);
		//Verify if character is not excluded, regen if it is
		while(!valid)
		{
			if(!exclusions[random])
				valid = true;
			else
			{
				random = (rand()/65536) % 126;
			}
		}
		string_buff[i] = (char)(random + 36);
	}
}

//Print total characters to screen
void print_chars(int chars_to_print)
{
	const int c_length = chars_to_print;
	char string_buff[c_length + 1];
	char * str_ptr = &string_buff[0];
	int threads = thread::hardware_concurrency();
	int print_per = (chars_to_print / (threads - 1));
	int offset = (chars_to_print % (threads - 1));
	for(int i = 0; i < thread::hardware_concurrency(); i++)
	{
		if(true)//i == threads - 1)
			generate_string(chars_to_print, str_ptr, offset);
		//else
		//	thread(generate_string, chars_to_print, str_ptr).detach();
	}
	//Print characters to screen
	printf("%s\n", string_buff);
}

int main(int argc, char * argv[])
{
	//Length of string to generate
	int string_length;
	for(int i = 1; i < argc; i++)
	{
		//Exclusion list handler
		if(strcmp(argv[i], "-e") == 0)
		{
			if(i + 1 < argc)
			{
				if(!silent_mode)
					printf("Excluding characters '%s'\n", argv[i+1]);
				set_exclusions(argv[i+1]);
				i++;
			}
			else
			{
				if(!silent_mode)
					printf("'-e' flag given but no exclusions given\n");
				return 1;
			}
		}
		//Get provided length for string
		else if(strcmp(argv[i], "-l") == 0)
		{
			if(i + 1 < argc)
			{
				string_length = strtol(argv[i+1], NULL, 10);
				if(string_length == 0)
				{
					printf("'%s' is not a valid length\n", argv[i+1]);
					return 1;
				}
				i++;
			}
			else
			{
				if(!silent_mode)
					printf("'-l' provided but no length specified\n");
			}
		}
		//Get help request
		else if(strcmp(argv[i], "-h") == 0)
		{
			print_help();
			return 0;
		}
		//Quiet mode, disables non-essential output
		else if(strcmp(argv[i], "-q") == 0)
		{
			silent_mode = true;
		}
	}
	if(!silent_mode)
		printf("Generating string %i characters long\n", string_length);
	print_chars(string_length);
	printf("\n");
	return(0);
}
