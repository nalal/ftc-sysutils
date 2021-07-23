#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

static char * launch_command = "steam steam://rungameid/";

static int a_list_size = 1;

static char * game_alias_list[] = { 
	"zomboid~108600"
};

bool has_alpha(char * str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		if(isalpha(str[i]))
			return true;
		else
			i++;
	}
	return false;
}

int get_str_length(char * str)
{
	int i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}

char * get_id(char * alias_entry)
{
	char * id = strchr(alias_entry, '~') + 1;
	return id;
}

char * get_alias_id(char * alias)
{
	for(int i = 0; i < a_list_size; i++)
	{
		if(strstr(game_alias_list[i], alias) != NULL)
		{
			char * id = get_id(game_alias_list[i]);
			return id;
		}
	}
	char * ret = "INVALID";
	return ret;
}

char * gen_run_comm(char * game_id, char * run_comm)
{
	
	strcpy(run_comm, launch_command);
	strcat(run_comm, game_id);
	return run_comm;
}


void launch_game(char * game_title)
{
	char run_comm[100];
	printf("Launching game %s\n", game_title);
	if(has_alpha(game_title))
	{
		char * id = get_alias_id(game_title);
		printf("ID is %s\n", id);
		system(gen_run_comm(id, &run_comm));
	}
	else
		system(gen_run_comm(game_title, &run_comm));
}

int main(int argc, char * argv[])
{
	switch(argc)
	{
		case 1:
			printf("No launch target provided...\n");
			return argc;
			break;
		default:
			launch_game(argv[1]);
	}
	return 0;
}
