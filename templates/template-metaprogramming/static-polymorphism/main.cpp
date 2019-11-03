/*
	Polymorphism is a classic feature of C++. However, to do
	something like virtual functions, you need to use a virtual
	look-up table. Such a stucture is traversed at runtime, and
	can be slow as molasses.

	Using template metaprogramming, you can resolve polymorphism at
	compile time. We call this "static polymorphism".

	Taken from here:
	https://en.wikipedia.org/wiki/Template_metaprogramming#Static_polymorphism
*/

#include <iostream>

using namespace std;

/*
	STANDARD POLYMORPHISM:
	method() is a virtual function. To resolve the function call, we need a vtable to call
	the right one. This incurs overhead everytime it's called. It's small, sure. But it's still
	there.
*/

class Base {
	public:
		virtual ~Base() { }
		virtual void method() { cout << "Base" << endl; }
};

class Derived : public Base {
	public:
		void method() { Base::method(); cout << "Derived" << endl; }
};

void regular_polymorphism() {
	Base* obj = new Derived;
	obj->method();
	delete obj;
}

/*
	STATIC POLYMORPHISM:
	We implement a similar relationship to the above. This employs what is called the Curriously Recurring Template Pattern.
	This is a form of F-Bounded quantification:

	https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
*/
template <class Derived>
struct base {
	void interface() {
		static_cast<Derived*>(this)->implementation();
	}

	void implementation() {
		cout << "The thing base" << endl;
	}
};

struct derived : base<derived> {
	void implementation() {
		cout << "The thing" << endl;
		base::implementation();
	}
};

void static_polymorphism() {
	base<derived>* obj = new base<derived>;
	obj->interface();
	delete obj;
}

int main() {
	regular_polymorphism();
	static_polymorphism();

	return 0;
}
