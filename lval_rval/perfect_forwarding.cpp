// Liam Wynn, 6/19/2020, C++ Learning

/*
	Demonstrating perfect-forwarding. When you have templates,
	you want to make sure the right kind of value (r or l) is being
	passed.
*/

#include <utility> // Defines std::forward

class bloatVector {
	public:
		bloatVector() {
			size = 10000;
			array = new double[size];
			for(int i = 0; i < size; i++)
				array[i] = 0;
		}

		bloatVector(const bloatVector& b) {
			size = b.size;

			array = new double[size];
			for(int i = 0; i < size; i++)
				array[i] = b.array[i];
		}

		bloatVector(bloatVector&& b) {
			size = b.size;
			array = b.array;

			b.size = 0;
			b.array = 0;
		}

		~bloatVector() {
			if(array)
				delete[] array;
			array = 0;

			size = 0;
		}

	private:
		int size;
		double* array;
};

bloatVector createBloat() {
	bloatVector result;

	return result;
}

void foo(bloatVector b) {
}

// Will give the appropriate value when we use std::forward.

/*
	How the heck does this work?

	Okay so first we need to know some rules about how C++ solves
	template references. I will present the rules without explanation:

	1. T& &		====>	T&
	2. T&& &	====>	T&
	3. T& &&	====>	T&
	4. T&& &&	====>	T&&

	Then suppose I call (call with rvalue reference)
	relay(9) ==> T = int&& (9 is rvalue) => int&& && => int&& (See rule 4)

	What about (call with lvalue reference)?
	relay(x) ==> T = int& => int& && => int& (See rule 3)

	This makes T&& in the function a universal type. Why isn't it an rvalue
	reference? It fulfills two conditions:

	1. It's a tempate type.
	2. Type deduction happens to T.
		- T is a function template type, not class template type.
*/
template<typename T>
void relay(T&& arg) {
	foo(std::forward<T>(arg));
}

int main() {
	// Gives lvalue
	bloatVector b = createBloat();
	relay(b);

	// gives rvalue
	relay(createBloat());

	return 0;
}
