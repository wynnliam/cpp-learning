/*
	From: https://www.geeksforgeeks.org/vector-in-cpp-stl/

	Summary of the functions used and what they do:

    size() – Returns the number of elements in the vector.
    max_size() – Returns the maximum number of elements that the vector can hold.
    capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
    resize(n) – Resizes the container so that it contains ‘n’ elements.
    empty() – Returns whether the container is empty.
    shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
    reserve() – Requests that the vector capacity be at least enough to contain n elements.

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> myVector;

	for(int i = 0; i < 10; i++)
		myVector.push_back(i);

	cout << "Size: " << myVector.size() << endl;
	cout << "Capacity: " << myVector.capacity() << endl;
	cout << "Max_size: " << myVector.max_size() << endl;

	// Will only see the first four elements because that's all it can store now.
	// Note that no memory mangement needs to be done it would seem.
	myVector.resize(4);
	for(auto i = myVector.cbegin(); i != myVector.cend(); i++)
		cout << *i << " ";
	cout << endl;
	cout << "Size after resizing: " << myVector.size() << endl;
	cout << "Capacity after resizing: " << myVector.capacity() << endl;

	if(myVector.empty())
		cout << "The vector is empty" << endl;
	else
		cout << "The vector is not empty" << endl;

	myVector.shrink_to_fit();
	for(auto i = myVector.cbegin(); i != myVector.cend(); i++)
		cout << *i << " ";
	cout << endl;
	cout << "Size after shrink: " << myVector.size() << endl;
	cout << "Capacity after shrink: " << myVector.capacity() << endl;

	return 0;
}
