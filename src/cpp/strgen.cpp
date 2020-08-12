#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//Maximum length of a generated string
const int MAX_CHARACTER_GEN = 256;
//Default length of a string
const int DEF_LENGTH = 16;

//Array of bools for exclusions
bool exclusions[126 - 36];
//Print nothing
bool silent_mode = false;

//Print help message
void print_help()
{
	printf("USAGE:\n    strgen\n");
	printf("'-e':\n    Exclude specific characters\n");
	printf("'-l':\n    String length (max %i)\n", MAX_CHARACTER_GEN);
}

//Set characters in string as excluded
void set_exclusions(char * excluded_chars)
{
	size_t chars = strlen(excluded_chars);
	for(int i = 0; i < chars - 1; i++)
	{
		exclusions[(int)excluded_chars[i] - 36] = true;
	}
}

int main(int argc, char * argv[])
{
	//Length of string to generate
	int string_length = DEF_LENGTH;
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
					printf("'-e' flag given but no exclusions provided\n");
			}
		}
		//Get provided length for string
		else if(strcmp(argv[i], "-l") == 0)
		{
			if(i + 1 < argc)
			{
				string_length = strtol(argv[i+1], NULL, 10);
				if(string_length > MAX_CHARACTER_GEN)
				{
					if(!silent_mode)
						printf(
							"Cannot generate string longer than %i\n", 
							MAX_CHARACTER_GEN
						);
					if(!silent_mode)
						printf("Generating largest string possible\n");
					string_length = MAX_CHARACTER_GEN;
				}
				if(string_length == 0)
				{
					printf("'%s' is not a valid length\n", argv[i+1]);
					string_length = DEF_LENGTH;
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
		else if(strcmp(argv[i], "-q") == 0)
		{
			silent_mode = true;
		}
	}
	time_t result = time(NULL);
	if(!silent_mode)
		printf("Generating string %i characters long\n", string_length);
	srand(result);
	char random_string[MAX_CHARACTER_GEN + 1];
	random_string[string_length] = '\0';
	for(int i = 0; i < string_length; i++)
	{
		bool valid = false;
		int random = (rand()/65536) % (126 - 36);
		while(!valid)
		{
			if(!exclusions[random])
				valid = true;
			else
			{
				random = (rand()/65536) % 126;
			}
		}
		random_string[i] = random + 36;
	}
	printf("%s\n", random_string);
	return(0);
}
