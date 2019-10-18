#include <iostream>
#include <algorithm>

using namespace std;

void show(int a[]);

int main() {
	int a[10] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

	cout << "Array before sorting" << endl;
	show(a);

	sort(a, a + 10);
	cout << "Array after sorting" << endl;
	show(a);

	sort(a, a + 10, greater<int>());
	cout << "Array after sorting but descending order" << endl;
	show(a);

	return 0;
}

void show(int a[]) {
	for(int i = 0; i < 10; i++)
		cout << a[i] << " ";

	cout << endl;
}
