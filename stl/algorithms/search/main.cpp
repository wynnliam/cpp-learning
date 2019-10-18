#include <iostream>
#include <algorithm>

using namespace std;

void show(int a[]) {
	for(int i = 0; i < 10; i++)
		cout << a[i] << " ";

	cout << endl;
}

int main() {
	int a[] = { 1, 5, 9, 0, 2, 8, 3, 6, 4, 7 };

	cout << "The array before sorting:" << endl;
	show(a);

	// RULE: Before calling binary_search, the array must be sorted
	sort(a, a + 10);
	cout << "The array after sorting:" << endl;
	show(a);

	if(binary_search(a, a + 10, 5))
		cout << "Found the item!" << endl;
	else
		cout << "Did not find the item!" << endl;

	return 0;
}
