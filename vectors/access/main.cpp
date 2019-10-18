#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> myVector;

	for(int i = 0; i < 10; i++)
		myVector.push_back(i);

	cout << "Reference operator [] at position 2: " << myVector[2] << endl;
	cout << "Using the at function at position 3: " << myVector.at(3) << endl;
	cout << "Using the front operation: " << myVector.front() << endl;
	cout << "Using the back operation: " << myVector.back() << endl;

	// If you want, you can use this operation. Strongly disadvise tho.
	int* datum = myVector.data();
	cout << "The first time is " << *datum << endl;

	return 0;
}
