#include "bitparse.h"

//Check if int is even/odd
bool is_odd(int in)
{
	//printf("%i is %s\n", in, (in & 0x01) ? "odd" : "even");
	return (bool)(in & 0x01);
}

//Prints bits from int to screen
void read_bits(int in)
{
	printf("Reading %i bits for int %i\n", sizeof(in) * 8, in);
	for(int i = sizeof(in) * 8 - 1; i >= 0; i--)
	{
		printf("%i",((in >> i)  & 0x01));
	}
	printf("\n");
}

/*
int main(int argc, char * argv[])
{
	for(int i =1; i < argc; i++)
	{
		int in = atoi(argv[i]);
		read_bits(in);
		printf("%i is %s\n", in, is_odd(in) ? "odd" : "even");
	}
	return 0;
}
*/
