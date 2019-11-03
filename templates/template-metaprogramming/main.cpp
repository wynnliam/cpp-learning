/*
	Taken from: https://www.geeksforgeeks.org/template-metaprogramming-in-c/

	With templates, you can pass non-type parameters. Values of enum constants
	are evaluated at compile time. Using these, we can write Turing-complete
	programs using templates. The cool thing is that such programs are evaluated
	at compile time! That is, any computation that a program can express can in
	some form be expressed by a template metaprogram.

	I notice too the similarities to functional programming here. Suppose
	we wrote this in Haskell. It'd look something like:

	power_struct 0 = 1
	power_struct n = 2 * power_struct (n - 1)

	There are no mutable variables in template metaprogramming. In this way,
	it is also highly functional.

	This template metaprogramming can help the compiler write optimizations to code.
	If you supplied a size parameter via templates, the compiler can do
	say loop unrolling.
*/

#include <iostream>

using namespace std;

template<int n>
struct power_struct {
	enum {
		val = 2 * power_struct<n - 1> :: val
	};
};

template<>
struct power_struct <0> {
	enum { val = 1};
};

int main() {
	cout << power_struct<8> :: val << endl;
	return 0;
}
