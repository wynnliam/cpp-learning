/*
	If you know me in real life, you know I loooove functional stuff. So when
	I learned about lambdas, I was really exicted to dive into them. It took me
	awhile, but I finally get to explore them here!

	Tutorial I'm using comes from here:
	https://blog.feabhas.com/2014/03/demystifying-c-lambdas/

	Lambda's are basically ad-hoc locally scoped function objects. As I understand it,
	they are function objects done with sugar syntax.
*/

#include <iostream>

using namespace std;

void demo_01_basic_lambda();

void split() {
	cout << "-----" << endl;
}

int main() {
	cout << "First demo" << endl;
	split();
	demo_01_basic_lambda();
	split();

	return 0;
}

void demo_01_basic_lambda() {
	/* The anatomy of the lambda:
		[] - mark the declaration of the lambda

		(int a) - specifies the parameters. Passed using standard application
		binary interface (ABI).

		-> int - The trailing return type. This is for ease of parsing. Note
		that the return type is not needed if the result is void or can be deduced
		from a "return" statement.

		{ ... } - Finally, the body of the lambda.

		An important note: lambdas are objects, but they're type is known
		only by the compiler. Hence, we must use the auto keyword here
	*/
	auto example_lambda = [](int a) -> int { return a + 1; };

	int p = 10;
	cout << "Input is " << p << endl;
	cout << "Resulting lambda application is " << example_lambda(p) << endl;
}
