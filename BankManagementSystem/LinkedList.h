#pragma once
#include <iostream>
using namespace std;


enum Error_code { success, overflow, underflow, not_found };

template <class T>
struct Node {
	T entry;
	Node* next;
	//constructors
	Node();
	Node(T item, Node<T>* link = NULL);
};

template <class T>
class List {
public:
	List();
	void clear();
	bool empty() const;
	int size() const;
	Error_code remove(const T& item);
	Error_code insert(const T& item);
	Error_code search(T& item);//also include traverse??
	Error_code modify();//to update also change balance
	void print() const;
	// Safequards
	~List();
	List(const List<T>& copy);
	void operator = (const List<T>& original);
protected:
	Node<T>* head;
};
