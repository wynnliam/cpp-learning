// liam wynn, 6/20/2020, c++ learning

/*
	A small set of examples for handling threads and code failures.
	to compile:
	g++ -lpthread 00.cpp
*/

#include <iostream>
#include <thread>

using namespace std;

void thread_function() {
	cout << "Hello from t1" << endl;
}

void execute() {
	std::thread t1(thread_function);
}

int main() {
	// If we do not join or detach, we get an error!
	//execute();
	//while(true);

	// We don't have to immediately join or detach,
	// but we need to put intermediate code in a try-catch
	// block. If we don't we could lose the thread object
	// and get an error.
	std::thread t1(thread_function);

	try {
		for(int i = 0; i < 100; i++) {
			cout << "main: " << i << endl;

			if(i == 32)
				throw 32;
		}
	} catch(...) {
		t1.join(); // Try commenting this out and see what happens!
		return 1;
	}

	t1.join();
	return 0;
}
