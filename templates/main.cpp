#include <iostream>

using namespace std;

// Demo for how function templates work.
template <typename T>
T myMax(T x, T y) {
	return (x > y) ? x : y;
}

// Template class demo
template <typename T>
class Structure {
	public:
		Structure(T arr[], int s);
		~Structure();
		void print();

	private:
		T* ptr;
		int size;
};

template <typename T>
Structure<T>::Structure(T arr[], int s) {
	ptr = new T[s];
	size = s;

	for(int i = 0; i < size; i++)
		ptr[i] = arr[i];
}

template <typename T>
Structure<T>::~Structure() {
	delete[] ptr;
	ptr = NULL;
}

template <typename T>
void Structure<T>::print() {
	for(int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}

// Template demo with multiple types
template<typename T, typename U>
class Pair {
	public:
		T head;
		U tail;

		Pair() { cout << "Pair constructor called" << endl; }
};

int main() {
	// Template function demo.
	cout << myMax<int>(3, 7) << endl;
	cout << myMax<char>('g', 'e') << endl;

	// Template class demo.
	int arr[5] = { 1, 2, 3, 4, 5 };
	Structure<int> a(arr, 5);

	a.print();

	Pair<char, int> b;

	return 0;
}
