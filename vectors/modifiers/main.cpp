/*
	From: https://www.geeksforgeeks.org/vector-in-cpp-stl/

	Summary of functions and their use:
	assign() – It assigns new value to the vector elements by replacing old ones
	push_back() – It push the elements into a vector from the back
	pop_back() – It is used to pop or remove elements from a vector from the back.
	insert() – It inserts new elements before the element at the specified position
	erase() – It is used to remove elements from a container from the specified position or range.
	swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
	clear() – It is used to remove all the elements of the vector container
	emplace() – It extends the container by inserting new element at position
	emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> myVector;

	// Puts five copies of the value ten into the vector.
	myVector.assign(5, 10);

	for(auto i = myVector.cbegin(); i != myVector.cend(); i++)
		cout << *i << " ";
	cout << endl;

	myVector.push_back(15);
	cout << "The last element to be added is: " << myVector.back() << endl;

	// Remove the last element
	myVector.pop_back();
	cout << "The last element is now (after popping): " << myVector.back() << endl;

	// Insert a five at the beginning
	myVector.insert(myVector.begin(), 5);
	cout << "The element at the front is now: " << myVector.front() << endl;

	// Remove the first element using erase
	myVector.erase(myVector.begin());
	cout << "The element at the front is now: " << myVector.front() << endl;

	// Use emplace to add an element to the front
	myVector.emplace(myVector.begin(), 5);
	cout << "The element at the front is now: " << myVector.front() << endl;

	// Use emplace_back to add an element to the back
	myVector.emplace_back(20);
	cout << "The last element is: " << myVector.back() << endl;

	cout << "Vector size before clear " << myVector.size() << endl;
	myVector.clear();
	cout << "Vector size after clear " << myVector.size() << endl;

	// Demo for swap
	cout << endl;

	vector<int> v1, v2;

	v1.assign(5, 1);
	v2.assign(5, 2);

	cout << "Items in v1" << endl;
	for(auto i = v1.cbegin(); i != v1.cend(); i++)
		cout << *i << " ";
	cout << endl;

	cout << "Items in v2" << endl;
	for(auto i = v2.cbegin(); i != v2.cend(); i++)
		cout << *i << " ";
	cout << endl;

	v1.swap(v2);
	cout << "Contents after swapping" << endl;
	
	cout << "Items in v1" << endl;
	for(auto i = v1.cbegin(); i != v1.cend(); i++)
		cout << *i << " ";
	cout << endl;

	cout << "Items in v2" << endl;
	for(auto i = v2.cbegin(); i != v2.cend(); i++)
		cout << *i << " ";
	cout << endl;
	return 0;
}
