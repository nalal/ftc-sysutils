#include <iostream>
#include <thread>

using std::thread;
using std::cout;

int main()
{
	cout << "Total threads: " << thread::hardware_concurrency() << "\n";
	return 0;
}
