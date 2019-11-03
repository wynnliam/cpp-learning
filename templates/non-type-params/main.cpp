// Liam Wynn, 11/3/2019, C++ Learning

#include <iostream>

using namespace std;

// This is valid.
template <int n>
void foo() {
	cout << n << endl;
}

template <void (*f)()>
void f_ptr() {
	f();
}

/*
	This is invalid! There are rules to what constitutes a template non-type parameter.

 	A non-type template-parameter shall have one of the following (optionally cv-qualified) types:
    -- integral or enumeration type,
    -- pointer to object or pointer to function,
    -- lvalue reference to object or lvalue reference to function,
    -- pointer to member,
    -- std::nullptr_t.

	Why would you want to use these? I mean, that question could go for anything. But it
	seems to me that you could use them to say specify a size parameter for a class or something.
*/
/*template <float m>
void bar() {
	cout << m << endl;
}*/

int main() {
	foo<3>();
	f_ptr<&foo<3>>();
	//bar<2.74>();

	return 0;
}
