#include <iostream>
#include "CircularList.h"

using namespace std;

int main() {

	CircularList cl("Jim");

	cl.insert("Jack");
	cl.insert("John");
	cl.insert("Mary");
	cl.insert("Alice");
	cl.insert("Nancy");
	cl.insert("Mike");
	cl.insert("Tim");
	cl.insert("Nick");
	cl.insert("Tom");

	cl.print(true);
	cout << "-------------------------------------------" << endl;

	cl.print(false);
	cout << "-------------------------------------------" << endl;

	cout << "There are " << cl.getSize() << " names in the list." << endl;
	cout << "-------------------------------------------" << endl;

	cl.roll(true, 1);
	cl.print(true);
	cout << "-------------------------------------------" << endl;

	cl.roll(true, 15);
	cl.print(true);
	cout << "-------------------------------------------" << endl;

	cl.remove();
	cl.print(true);
	cout << "-------------------------------------------" << endl;

	for (int i = 0; i<10; i++) {
		string name = cl.remove();
		cout << name << " removed from the list!" << endl;
	}

	return 0;
}
