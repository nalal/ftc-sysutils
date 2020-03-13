#include <iostream>
#include <thread>

using std::thread;
using std::cout;

int main(int argc, int argv)
{
	if(argc > 1)
	{
		cout << thread::hardware_concurrency();
	}
	else
	{
		cout << "Total threads: " << thread::hardware_concurrency() << "\n";
	}
	return 0;
}
