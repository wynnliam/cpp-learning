// Liam Wynn, 6/11/2020, C++ Learning

// To run, do:
// g++ concept.cpp -std=c++2a

#include <string>
#include <cstddef>
#include <concepts>

using namespace std::literals;

template<typename T>
concept Hashable = requires(T a) {
	// I don't really understand this syntax.
	{ std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};

struct meow {};

// Says that we may only give it a type that is Hashable.
// It validates this AT COMPILE TIME
template<Hashable T>
void f(T) {
	// TODO: Something here!
}

int main() {
	f("abc"); // This is ok
	f(meow {}); // NOT okay
	return 0;
}
