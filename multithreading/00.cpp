// liam wynn, 6/20/2020, c++ learning

/*
	a tiny introduction to multithreading in c++

	to compile:
	g++ -lpthread 00.cpp
*/

#include <iostream>
#include <thread>

using namespace std;

void function_1() {
	cout << "Hello from function 1" << endl;
}

int main() {
	std::thread t1(function_1); // Starts t1
	//t1.join(); // Main thread waits for t1 to finish.
	t1.detach(); // t1 will run freely on its own. -- t1 is now a daemon process
	// Doing this will typically cause no output.
	// main thread runs too fast for t1 to print.
	//while(true); // Uncomment this as well as detach to see t1 still print

	//t1.join(); // Once you detach, you cannot rejoin. This gives error

	// You can test joinability though like so
	if(t1.joinable())
		t1.join();

	return 0;
}
