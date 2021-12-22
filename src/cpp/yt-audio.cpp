#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	char * save_dir = "~/music";
	printf("[YT-AUDIO]\n");
	printf("=Checking for URLs...\n");
	switch(argc)
	{
		case 1:
			printf("=No URLs provided, halting.\n");
			break;
		default:
			char dir_make[256];
			printf("=Validating music DIR...\n");
			sprintf(dir_make, "mkdir -p %s", save_dir);
			system(dir_make);
			sprintf(dir_make, NULL);
			for(int i = 1; i < argc; i++)
			{
				printf("=Downloading %s\n", argv[i]);
				char runline[256];
				sprintf(
					runline, 
					"youtube-dl --throttled-rate 100K -f bestaudio %s -o '%s/\%(title)s.\%(ext)s'", 
					argv[i], 
					save_dir
				);
				system(runline);
				sprintf(runline, NULL);
			}
	}
	return 0;
}
