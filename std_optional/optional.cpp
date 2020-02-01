// Liam Wynn, 2/1/2020, C++ Learning

// See: https://www.bfilipek.com/2018/05/using-optional.html

/*
	std::optional is a vocabulary type where you essentially
	append a boolean value to an object's type. In doing so, you
	can more clearly express whether an object has a value or not.

	It's cousin in Haskell would be the Maybe type. It's great for
	situations where it's normal for a value to be empty. In cases
	where this produces errors, I would still use NULL or something.
*/

#include <iostream>
#include <optional>
#include <string>

using namespace std;

void demo_00();
void demo_01();

int main() {
	cout << "Welcome to the std::optional demo!" << endl;

	demo_00();
	demo_01();

	return 0;
}

/* DEMO 00 IMPLEMENTATION */

std::optional<std::string> get_nickname_from_user_id(const int& user_id) {
	if(user_id == 2)
		return { "Ratso" };
	else
		return std::nullopt;
}

void print_user(const int& id, const std::optional<std::string>& nickname) {
	cout << "User\nID = " << id << endl;
	cout << "Nickname = ";

	if(nickname)
		cout << *nickname;
	else
		cout << "None";

	cout << endl;
}

void demo_00() {
	cout << "\n--- DEMO 00 --- " << endl;
	cout << "Basic example: Using std::optional" << endl;
	cout << "In this example, we query user nicknames from id's" << endl;
	cout << "However, user's don't always have a nickname" << endl;
	cout << "We can express this cleanly with std::optional" << endl << endl;

	int user_id_a, user_id_b;

	user_id_a = 2;
	user_id_b = 74;

	std::optional<std::string> nickname_a = get_nickname_from_user_id(user_id_a);
	std::optional<std::string> nickname_b = get_nickname_from_user_id(user_id_b);

	print_user(user_id_a, nickname_a);
	print_user(user_id_b, nickname_b);

	cout << endl;
}

/* --- */

/* DEMO 01 IMPLEMENTATION */
class User {
	public:
		User(const std::string& newName) : name(newName) {
			cout << "Constructor Name: " << name << endl;
		}

		~User() {
			cout << "Destructor Name: " << name << endl;
		}

	private:
		std::string name;
};

void demo_01() {
	cout << "\n--- DEMO 01 --- " << endl;
	cout << "In this demo, we explore assignment and modification of optionals" << endl;

	std::optional<User> currUser;

	currUser.emplace("Steve");

	// Calls ~Steve and calls Mark
	currUser.emplace("Mark");

	// Resets so its empty
	currUser.reset();
	// This is the same as calling ~Mark then assigning it to nullopt

	currUser.emplace("Frank");
	currUser = User("Jimmy");

	cout << endl;
}

/* --- */
