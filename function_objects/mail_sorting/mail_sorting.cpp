#include "./message.h"

using namespace std;

int main() {
	Message m("John Smith", "RE: Stats problem", "No that's not right.");
	MessageDisplayHandler d(false);

	d(m);

	return 0;
}
