/*
	If you know me in real life, you know I loooove functional stuff. So when
	I learned about lambdas, I was really exicted to dive into them. It took me
	awhile, but I finally get to explore them here!

	Tutorial I'm using comes from here:
	https://blog.feabhas.com/2014/03/demystifying-c-lambdas/

	Lambda's are basically ad-hoc locally scoped function objects. As I understand it,
	they are function objects done with sugar syntax.

	Please, do read the link above. One thing I will not cover here is what
	happens under the hood. Basically, a lambda becomes a function object
	at compile time. The client code is updated to use this.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void demo_01_basic_lambda();
void demo_02_adhoc_function();
void demo_03_inline_lambda();
void demo_04_context_capture();

void split() {
	cout << "-----" << endl;
}

int main() {
	cout << "Demo 01" << endl;
	split();
	demo_01_basic_lambda();
	split();

	cout << "Demo 02" << endl;
	split();
	demo_02_adhoc_function();
	split();

	cout << "Demo 03" << endl;
	split();
	demo_03_inline_lambda();
	split();

	cout << "Demo 03" << endl;
	split();
	demo_04_context_capture();
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

void demo_02_adhoc_function() {
	/*
		Lambdas are a powerful tool! They allow us to create ad-hoc functions
		in local scope. This was illegal in C++ before. Now we needn't create
		a functor to print a list of example_structs, as seen here.
	*/

	struct example_struct {
		int x, y;
	};

	auto printer = [](example_struct& e) -> void { cout << e.x << ", " << e.y << endl; };

	vector<example_struct> points;

	points.push_back({0, 1});
	points.push_back({2, 3});
	points.push_back({4, 5});
	points.push_back({6, 7});
	points.push_back({8, 9});

	for_each(points.begin(), points.end(), printer);
}

void demo_03_inline_lambda() {
	/*
		You can take the result from demo 02 to the extreme.
		In this demo, I scan each point, looking for the one whose
		x coordinate is 4.
	*/

	struct example_struct {
		int x, y;
	};

	vector<example_struct> points;

	points.push_back({0, 1});
	points.push_back({2, 3});
	points.push_back({4, 5});
	points.push_back({6, 7});
	points.push_back({8, 9});

	auto i = find_if(points.begin(), points.end(), [](example_struct& e) -> bool { return e.x == 4; });

	if(i != points.end())
		cout << i->x << ", " << i->y << endl;

}

void demo_04_context_capture() {
	/*
		What makes function objects so neat? Not only do
		you overload the function call operator, but you can
		supply additional parameters via class/struct members.

		This makes it much easier to handle say special cases
		for printing a list. Do you want to print only certain items?
		You can do that by specifying members for the function object.

		How about a lambda? In the above scenario, we returned the
		first point whose x coordinate was 4, but we hard-coded that.
		It would be nice to be able to parameterize that some how.

		In this demo, we do so with "context-capturing". Context-capturing
		enables us to access variables outside of the lambda. This isn't
		just passing an argument. Consider in this demo. We use the
		for_each algorithm. If we supplied an additional argument, we
		would not be able to use it in for_each.
	*/

	int multiplier = 5;
	vector<int> inputs;

	inputs.push_back(0);
	inputs.push_back(1);
	inputs.push_back(2);
	inputs.push_back(3);
	inputs.push_back(4);

	auto do_scale  = [multiplier](int& x) -> void { x *= multiplier; };
	auto print = [](int& x) -> void { cout << x << " "; };

	cout << "Inputs before scaling" << endl;
	for_each(inputs.begin(), inputs.end(), print);
	cout << endl;

	for_each(inputs.begin(), inputs.end(), do_scale);

	cout << "Inputs after scaling" << endl;
	for_each(inputs.begin(), inputs.end(), print);
	cout << endl;
}
