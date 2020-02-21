#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	char * save_dir = "~/music";
	printf("[YT-AUDIO]\n");
	printf("=Checking for URLs...\n");
	if(argc > 1)
	{
		char dir_make[256];
		printf("=Validating music DIR...");
		sprintf(dir_make, "mkdir -p %s", save_dir);
		system(dir_make);
		sprintf(dir_make, NULL);
		for(int i = 1; i < argc; i++)
		{
			printf("=Downloading %s\n", argv[i]);
			char runline[256];
			sprintf(
				runline, 
				"youtube-dl -f bestaudio %s -o '%s/\%(title)s.\%(ext)s'", 
				argv[i], 
				save_dir
			);
			system(runline);
			sprintf(runline, NULL);
		}
	}
	else
	{
		printf("=No URLs provided, halting.\n");
	}
	//sprintf(save_dir, NULL);
	return 0;
}
