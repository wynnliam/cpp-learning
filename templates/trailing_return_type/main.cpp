#include <iostream>

using namespace std;

/*
	This tutorial is taken from: https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/introduction_to_the_c_11_feature_trailing_return_types?lang=en
*/

/*
	Here's a happy little multiply function:
*/

/*
template <typename T>
T mul(T a, T b) {
	return a * b;
}
*/

/*
	For computing the product, T is not decided until
	the template is instantiated (so I'm assuming the instantiation
	occurs when the function is called). This
	means that we can't define mul for all cases.

	As such, we must introduce a second type U as follows.
*/


/*template <typename T, typename U>
U mul(T a, T b) {
	return a * b;
}*/


/*
	This gives us an error! It cannot deduce the type U.
*/

/*
	Can we use decltype here? Let's try it.
*/
/*template <typename T>
decltype(a * b) mul(T a, T b) {
	return a * b;
}*/

/*
	Oh fiddlesticks, apparently not! The problem is that the compiler
	reads from left to right. It doesn't know what a and b are, so we get
	errors about how a and b are not declared in this scope.
*/

/*
	To solve this problem, C++ 11 introduced the Trailing Return Type.
	We can use this feature as follows:
*/
template <typename T>
auto mul(T a, T b) -> decltype(a * b) {
	return a * b;
}

/*
	The symbol "-> decltype(a * b)" is the trailing return type. This requires
	that we place the auto keyword where the return type is. We use this when the
	return type depends on the arguments. A better example is the sum function
	below.
*/

template <typename T, typename U>
auto sum(T a, U b) -> decltype(a + b) {
	return a + b;
}

/*
	Why don't we do something like:
*/
/*template <typename T, typename U>
auto sum(T a, U b) {
	return a + b;
}*/

/*
	Actually, you can! But there is a rule: the compiler always
	deduces by value, and never by reference! So if you want
	return by reference, you must use the trailing return type.

	Also, there are some cases where deduce simply fails. In such
	a case, use trailing return type.
*/

int main() {
	int a = 10;
	int b = 54;
	float c = 25.7f;

	cout << "Product of " << a << " and " << b << " is " << mul(a, b) << endl;
	cout << "Sum of " << a << " and " << c << " is " << sum(a, c) << endl;

	return 0;
}
