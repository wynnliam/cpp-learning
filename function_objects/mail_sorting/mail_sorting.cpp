#include "./message.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<Message> messages;
	MessageDisplayHandler dh;
	MessageSortingHandler sh;

	messages.push_back(Message("C", "C", "C"));
	messages.push_back(Message("H", "H", "H"));
	messages.push_back(Message("A", "A", "A"));
	messages.push_back(Message("B", "B", "B"));
	messages.push_back(Message("F", "F", "F"));
	messages.push_back(Message("D", "D", "D"));
	messages.push_back(Message("G", "G", "G"));
	messages.push_back(Message("E", "E", "E"));

	cout << "Messages unsorted:" << endl;
	for(auto i = messages.cbegin(); i != messages.cend(); i++)
		dh(*i);

	sort(messages.begin(), messages.end(), sh);

	cout << "Messages unsorted:" << endl;
	for(auto i = messages.cbegin(); i != messages.cend(); i++)
		dh(*i);

	return 0;
}
