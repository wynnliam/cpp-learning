#include "./message.h"
#include <iostream>

using namespace std;

/* Message Class Implementations */
Message::Message(string from, string header, string body) {
	this->from = from;
	this->header = header;
	this->body = body;
}

/* MessageDisplayHandler implementations */
void MessageDisplayHandler::operator() (const Message& toDisplay) {
	if(headerFirst) {
		cout << "Header: " << toDisplay.GetHeader() << endl;
		cout << "From: " << toDisplay.GetFrom() << endl;
	} else {
		cout << "From: " << toDisplay.GetFrom() << endl;
		cout << "Header: " << toDisplay.GetHeader() << endl;
	}

	cout << "Body: " << toDisplay.GetBody() << endl;
}
