/*
	Smart pointers: automate dynamic memory allocation.

	unique_ptr: When out of scope, gets deleted. Cannot be copied.

	shared_ptr: Keeps track of the number of references to a pointer.
	when the number of references is 0, then we free our memory.

	weak_ptr: Similar to a shared_ptr, but the ref count will not increase.
*/

#include <iostream>
#include <memory>

using namespace std;

class entity {
	public:
		entity() {
			cout << "Created entity!" << endl;
		}

		~entity() {
			cout << "Entity destroyed" << endl;
		}

		void print() {
			cout << "Printing!" << endl;
		}
};

void unique_ptr_demo() {
	{
		// unique_ptr uses an explicit constructor, so you must
		// explicitly invoke it (hence the "(new entity())") stuff.
		//unique_ptr<entity> my_entity(new entity());

		// Note that this is the preferred method to create a unique_ptr (exception safety)
		unique_ptr<entity> my_entity = make_unique<entity>();

		my_entity->print();

		// Will fail! Cannot copy unique_ptr's. Copy constructor and assignment operators
		// are deleted
		//unique_ptr<entity> my_other_entity = my_entity;
		//my_other_entity->print();
	}
}


void shared_ptr_demo() {
	{
		shared_ptr<entity> other_shared_entity;

		{
			// Allocate this way (ie not shared_entity(new Entity())). This
			// saves us one allocation. Shared ptr uses a control block to keep
			// reference count. Doing this way keeps the allocations in one place.
			shared_ptr<entity> shared_entity = make_shared<entity>();

			// Perfectly okay.
			other_shared_entity = shared_entity;

			shared_entity->print();
		}

		// Entity made in inner scope preserved thanks to copied pointer
		// in outer scope. Only after this will we free our entity. When all
		// of the references are gone, THEN we free the entity.
		cout << "other shared entity: ";
		other_shared_entity->print();
	}
}

int main() {
	cout << "Unique Pointer Demo" << endl;
	unique_ptr_demo();

	cout << "\nShared Pointer Demo" << endl;
	shared_ptr_demo();

	return 0;
}
