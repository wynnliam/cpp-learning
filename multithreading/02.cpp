// liam wynn, 6/20/2020, c++ learning

/*
	Thread management doing RAII:
	Resource acquisition is initialization

	The premise is we create a functor object to wrap the thread.
	This way, we can encapsulate the thread management in a nice way.

	to compile:
	g++ -lpthread 00.cpp
*/

#include <iostream>
#include <thread>

using namespace std;

class my_functor {
	public:
		void operator() (string& msg) {
			cout << "from t1: " << msg << endl;

			msg = "Trust is the mother of deceit.";
		}
};

int main() {
	string s = "Where there is no trust, there is no love";
	//my_functor f;
	//std::thread t1(f, s);
	// Thread parameters are ALWAYS passed by value,
	// This will fail to compile
	//std::thread t1((my_functor()), s);
	std::thread t1((my_functor()), std::ref(s));
	// Note if you wanted to give t1 ownership of s,
	// use std::move(s) in thread param.
	// Now message gets changed

	// Note that threads cannot be copied. You must move them:
	std::thread t2 = std::move(t1);

	// (Also, you can get thread id's in this way):
	cout << std::this_thread::get_id() << endl;
	cout << t2.get_id() << endl;

	// Now t2 is responsible
	t2.join();

	cout << "from main: " << s << endl;

	// How many threads can I run? I don't want too many.
	// Otherwise I can get oversubscription and my performance
	// degrades. We can use this function to get an idea as to
	// how many threads I can run
	cout << std::thread::hardware_concurrency() << endl;
	return 0;
}
