// Liam Wynn, 11/29/2019, Check Palindrome

/*
	Credit to one david_f25 on CodeSignal for this solution.
	Essentially given a string, return if it is a palindrome.
	I want this to be a learning experience so as to get better at C/C++.

	I will post my solution at some point. I must warn you: it's not good!
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// David's solution
int checkPalindrome(string s) {
	return s == string(rbegin(s), rend(s));
}

int main() {
	vector<string> tests;
	tests.push_back("aabaa");
	tests.push_back("abac");
	tests.push_back("a");
	tests.push_back("az");

	auto runner = [](const string& s) -> void { cout << s << " " << checkPalindrome(s) << endl; };

	for_each(tests.begin(), tests.end(), runner);

	return 0;
}
