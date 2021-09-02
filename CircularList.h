#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	// constructor
	Node(string name);
	
	// print node information
	void print();

	friend class CircularList;

private:
	string name;	// name of people
	Node* next;		// Pointer to the next node in list
	Node* prev;		// Pointer to the previous node in list
};

class CircularList {
public:
	// constructor
	CircularList();
	// constructor that has new person name as parameter
	CircularList(string newName);

	// Insert a new node to the current position of head pointer. Current head 
	// node will be the next node and new node will be the head node.
	void insert(string newName);
	// Moves the position of the head pointer N times to forward (dir = true)
	// or backward (dir = false)
	void roll(bool dir, int N);
	// Remove the node at head pointer. Returns that name. Head moves to the 
	// next name on the list.
	string remove();
	// Returns the number of names in the list
	int getSize();
	// Prints the whole list of names either in forward (dir = true) or backward
	// (dir = false)
	void print(bool dir);
	
private:
	Node* head;	// pointer to the first node in the list
	int size;	// number of nodes in the list
};

#endif
