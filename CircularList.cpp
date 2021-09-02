#include "CircularList.h"

Node::Node(string newName) {
	name = newName;
	next = NULL;
	prev = NULL;
}

// print node information
void Node::print() {
	cout << name << endl;
}

// constructor
CircularList::CircularList() {
	head = NULL;
	size = 0;
}

// constructor that has new person name as parameter
CircularList::CircularList(string newName) {
	head = NULL;
	size = 0;
	insert(newName);
}

// Insert a new node to the current position of head pointer. Current head 
// node will be the next node and new node will be the head node.
void CircularList::insert(string newName) {
	// create new node
	Node* node = new Node(newName);

	if (head == NULL) {
		node->next = node;
		node->prev = node;
	}
	else {
		node->next = head;
		node->prev = head->prev;
		node->next->prev = node;
		node->prev->next = node;
	}

	head = node;

	// increment size
	size++;
}

// Moves the position of the head pointer N times to forward (dir = true)
// or backward (dir = false)
void CircularList::roll(bool dir, int N) {
	if (head == NULL)
		return;

	if (dir) {
		for (int i = 1; i <= N; i++) {
			head = head->next;
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			head = head->prev;
		}
	}
}

// Remove the node at head pointer. Returns that name. Head moves to the 
// next name on the list.
string CircularList::remove() {
	// if list is empty
	if (head == NULL) {
		// print error message
		cout << "Error: linked list is empty" << endl;
		return "";
	}
	else {
		// get the name at head
		string name = head->name;
		// node to be removed
		Node* node = head;

		// if only single node in the list
		if (node->next == head) {
			// make list empty
			head = NULL;
		}
		else {
			node->next->prev = node->prev;
			node->prev->next = node->next;
			head = node->next;
		}

		// delete node
		delete node;

		// decrement size
		size--;

		// return name
		return name;
	}
}

// Returns the number of names in the list
int CircularList::getSize() {
	return size;
}

// Prints the whole list of names either in forward (dir = true) or backward
// (dir = false)
void CircularList::print(bool dir) {
	Node* node = head;

	if (dir) {
		for (int i = 0; i < size; i++) {
			cout << node->name << "\t";
			node = node->next;
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << node->name << "\t";
			node = node->prev;
		}
	}

	cout << endl;
}
