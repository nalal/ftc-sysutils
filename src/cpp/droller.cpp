#include "main.h"

/*======================================================================
 * PROGRAM:
 * 		Dice roller
 * 
 * AUTHOR:
 * 		Noah Germann
 * 
 * PURPOSE:
 * 		Act as a digital set of dice for rolling numbers within a set 
 * 		range
 * 
 * INIT DATE:
 * 		13-03-2020
 *======================================================================
 */


int threads_available = (unsigned)std::thread::hardware_concurrency();
int threads_in_use = 0;

// Array for rolls
int die_data[256];


int roll_die(int die_total, int current_die)
{
	int upper, lower;
	
	//Minimum roll of one
	lower = 1;
	//Sides of die
	upper = die_total;
	
	//Set seed with as many variables as possible
	srand(
		time(0) + 
		die_total + 
		current_die + 
		threads_available + 
		threads_in_use
	);
	
	printf("Rolling die with %i sides\n", die_total);
	double res = (rand() % (upper - lower + 1)) + lower;
	int num = res;
	res = NULL;
	//Announce roll value
	printf("=Rolled: %i\n", num);
	//Lower total threads in use
	threads_in_use = threads_in_use - 1;
	//Add value to list of roll values
	die_data[current_die - 1] = num;
	return num;
}

int main(int argc, char * argv[])
{
	printf("Testing d_any.\n");
	//Check if there are more dice than can be placed into static array
	if(argc > 256)
	{
		printf("Too many dice rolled, array overflow\n");
		return 2;
	}
	//Check if dice were provided in the first place
	else if(argc <=1)
	{
		printf("No dice provided\n");
		return 1;
	}
	//Set value for total dice from argc
	int total_dice = argc - 1;
	//Go through all provided die values and start gen on new thread
	for(int i = 1; i < argc; i++)
	{
		//Check for avaliable threads, wait if none
		while(threads_available = threads_in_use)
		{
			std::this_thread::sleep_for (std::chrono::microseconds(100));
		}
		//Check if value is numeric
		if(!atoi(argv[i]))
		{
			printf("%s is not a valid number of sides\n", argv[i]);
			total_dice - 1;
		}
		threads_in_use++;
		std::thread(roll_die, atoi(argv[i]), i).detach();
	}
	//Wait for all rolls to be completed
	while(threads_in_use >= 1)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}
	//If more than one dice rolled, get sum of all rolled
	if(total_dice >= 2)
	{
		int total = 0;
		for(int i = 0; i < argc; i++)
		{
			total = total + die_data[i];
		}
		printf("\n-Total rolled: %i\n", total);
	}
	return 0;
} 
