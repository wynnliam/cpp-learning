#include <string>

using namespace std;

class Message {
	public:
		Message(string from, string header, string body);

		string GetFrom() const { return from; }
		string GetHeader() const { return header; }
		string GetBody() const { return body; }

	private:
		string from;
		string header;
		string body;
};

struct MessageDisplayHandler {
	bool headerFirst;

	MessageDisplayHandler(const bool bHeaderFirst = true) { headerFirst = bHeaderFirst; }

	void operator() (const Message& toDisplay);
};

struct MessageSortingHandler {
	bool sortByHeader;

	MessageSortingHandler(const bool bSortByHeader = true) { sortByHeader = bSortByHeader; }

	bool operator() (const Message& lhs, const Message& rhs);
};
