#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> myVector;

	for(int i = 0; i < 10; i++)
		myVector.push_back(i);

	cout << "Output from beginning to end" << endl;
	// auto says "infer the type based on the value". Type inference basically.
	for(auto i = myVector.begin(); i != myVector.end(); ++i)
		cout << *i << " ";
	cout << endl;

	cout << "Output from end to beginning" << endl;
	for(auto i = myVector.rbegin(); i != myVector.rend(); ++i)
		cout << *i << " ";
	cout << endl;

	cout << "Output from cbegin to cend" << endl;
	for(auto i = myVector.cbegin(); i != myVector.cend(); ++i) {
		//(*i) += 1; Uncommenting this gives an error! You cannot
		// modify data when using cbegin and cend.
		cout << *i << " ";
	}
	cout << endl;

	cout << "Output from crbegin to crend" << endl;
	for(auto i = myVector.crbegin(); i != myVector.crend(); ++i) {
		//(*i) += 1; Uncommenting this gives an error! You cannot
		// modify data when using crbegin and crend.
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}
