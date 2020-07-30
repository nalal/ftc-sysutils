#include <iostream>
#include <thread>

using std::thread;
using std::cout;

int main(int argc, int argv)
{
	if(argc > 1)
	{
		printf("%i", thread::hardware_concurrency());
	}
	else
	{
		printf("Total threads: %i\n", thread::hardware_concurrency());
	}
	return 0;
}
