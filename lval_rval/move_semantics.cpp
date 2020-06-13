// Liam Wynn, 6/13/2020, C++ Learning

#include <iostream>

#include <time.h>

using namespace std;

void printint(int& i) { cout << i << endl; }
void printint(int&& i) { cout << i << endl; }
// void printint(int i) { } Cant have because this makes the function calls
// ambiguous.

class bloatVector {
	public:
		int size;
		double* arr;

		bloatVector() {
			size = 0;
			arr = 0;
		};

		bloatVector(const bloatVector& b) {
			size = b.size;
			arr = new double[size];
			for(int i = 0; i < size; i++) {
				arr[i] = b.arr[i];
			}
		}

		// This is called a move constructor
		bloatVector(bloatVector&& b) {
			size = b.size;
			arr = b.arr; // We don't need to copy!
			b.arr = 0;
			b.size = 0;
		}

		~bloatVector() {
			delete[] arr;
		}
};

bloatVector createBloat() {
	bloatVector result;

	int p = 100000;

	result.size = p;
	result.arr = new double[p];
	for(int i = 0; i < p; i++)
		result.arr[i] = i + 0.4;

	return result;
}

void printBloat(bloatVector v) {
}

int main() {
	// Okay let's start this by learning something called
	// an rvalue reference.
	int a = 5; // a is an lvalue
	int& b = a; // b is an lvalue reference.
	//int&& c; // c is an rvalue reference.

	// Okay why do I care about this?
	printint(a); // Calls printint(int& i) because a is an lvalue
	printint(5); // Calls printint(int&& i) because 5 is an rvalue
	
	// So that's... kind of neat? Seems like a lot of effort
	// for very little. Does this give us any other benefits?

	// This kind of overloading is very useful for resource management.

	// We define bloatVector as a class with a REALLY large amount of doubles.
	// Note that the bloatVector has a copy constructor, and these will make
	// gigantic copies everywhere!
	clock_t tv1, tv2;
	double time;
	tv1 = clock();
	bloatVector big = createBloat();
	printBloat(big);
	tv2 = clock();
	time = (tv2 - tv1) / (CLOCKS_PER_SEC / 1000.0);
	cout << "Time for expensive deep copy: " << time << endl;

	// But when we define an inexpensive shallow copy using move constructor,
	// it saves us a lot of time!

	tv1 = clock();
	printBloat(createBloat());
	tv2 = clock();
	time = (tv2 - tv1) / (CLOCKS_PER_SEC / 1000.0);
	cout << "Time for : " << time << endl;

	// Suppose we wanted to move the contents of big elsewhere without
	// copying. We can literally move the contents like so:
	cout << "big size before move: " << big.size << endl;
	bloatVector cloat = std::move(big);
	cout << "big size after move: " << big.size << endl;

	return 0;
}
