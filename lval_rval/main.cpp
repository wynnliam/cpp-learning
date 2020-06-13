// Liam Wynn, 6/13/2020, C++ Learning

/*
	Demoing lvalue and rvalues.

	Essentially, the rule is:
	lvalue - any identifiable object that takes up memory.
	rvalue - anything not an lvalue
*/

#include <iostream>

int square(int& x) {
	return x * x;
}

int square2(const int& x) {
	return x * x;
}

// Misconception: functions always return rvalue.
int my_global;
int& foo() {
	return my_global;
}

using namespace std;

int main() {
	int i = 5; //i is an lvalue and 5 is an rvalue.
	//5 = i + 1; //ERROR: lvalue required on left-hand of assignment.

	//lvalue reference. right hand side of assignment must be lvalue ...
	int& r = i;
	//int& p = 4; // ERROR: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
	// ... Unless it's constant.
	// Note that in this case, an lvalue is created with value 5 then assigned to
	// q.
	const int& q = 5;


	cout << "i: " << i << endl;
	cout << "r: " << r << endl;
	cout << "q: " << q << endl;

	r = 3;

	cout << "i: " << i << endl;
	cout << "r: " << r << endl;

	// Okay so why is all this important? Consider the following:
	cout << square(r) << endl; // Okay because type of r is lvalue reference.

	// What about this?
	//cout << square(2) << endl; //ERROR: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

	// Same error as with trying to create variable p! How do we fix this? Well take a look at square2.
	// How is it different from square?

	cout << square2(2) << endl;

	// It works because the type of the argument in square2 is a const lvalue. Recall this is okay, but
	// has a cost of making a temporary lvalue, assigning it 2, then passing it in.

	// Okay so here's where things get confusing....

	int y = 1; // Okay, y is lvalue and 1 is rvalue.
	int x = y + 2; // So far so good - x is an lvalue and y + 2 is an rvalue.
	x = y; // Okay then x is an lvalue but... y is also one. How can this be?

	// IN that context, y is transformed (implicitly) into an rvalue.

	// lvalues can be implicitly transformed into lvalue. However, the reverse isn't possible.
	// You can't transform an rvalue into an lvalue implicitly. It has to be done explicitly.

	// Consider:
	int v[3];
	*(v + 2) = 4; // (v + 2) is an rvalue, but the * operator makes it an lvalue

	// Fun example of lvalue abuse
	foo() = 50;
	cout << foo() << endl;

	// But array access almost always returns an lvalue!
	v[2] = 50;
	cout << v[2] << endl;

	// Misconception: lvalues are always modifiable
	const int con = 22;
	//con = 5; // ERROR: assignment of read-only variable con

	// Misconception: rvalues are not modifiable
	class dog {
		public:
			void bark() { cout << "woof!" << endl; }
	};

	dog().bark(); // dog() is rvalue, and we could in theory change it by adding code to do so in bark.

	return 0;
}
