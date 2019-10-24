/*
	Taken from this tutorial here:
	https://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html

	C++ allows classes to overload operator(). This is the function call operator.
	By doing so, we can basically treat objects as functions.
*/

#include <iostream>

using namespace std;

class MyFunctionObject {
	public:
		MyFunctionObject(int newX) : x(newX) { }

		int operator() (int y) { return x + y; }

	private:
		int x;
};

int main() {
	MyFunctionObject obj(3);

	cout << "3 + 4 is " << obj(4) << endl;

	return 0;
}
