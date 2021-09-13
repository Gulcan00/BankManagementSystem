#pragma once
#include <iostream>
#include <string>
using namespace std;


enum Error_code { success, overflow, underflow, not_found };

struct Account {
	int account_no;
	string first_name;
	string last_name;
	double balance;
};

template <class T>
struct Node {
	T entry;
	Node<T>* next;
	Node();
	Node(const T item, Node<T>* link = NULL);
};

template <class T>
class List {
public:
	List();
	void clear();
	bool empty() const;
	int size() const;
	void traverse(void(*visit)(T&));
	Error_code remove(const T& item);
	Error_code insert(const T& item);
	Error_code search(T& item) const;
	Error_code modify(string key, T &item);
	// Safequards
	~List();
	List(const List<T>& copy);
	void operator = (const List<T>& original);
private:
	Node<T>* head;
};


template <class T>
Node<T>::Node()
{
	next = NULL;
}

template <class T>
Node<T>::Node(const T item, Node<T>* add_on)
{
	entry = item;
	next = add_on;
}

template <class T>
List<T>::List()
{
	head = NULL;
}


template <class T>
void List<T>::clear()
{
	Node<T>* temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}


template <class T>
bool List<T>::empty() const
{
	return head == NULL;
}


template <class T>
int List<T>::size() const
{
	int count = 0;
	Node<T>* temp = head;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

template<class T>
void List<T>::traverse(void(*visit)(T&))
{
	Node<T>* temp = head;
	while (temp != NULL)
	{
		(*visit)(temp->entry);
		temp = temp->next;
	}
}


template <class T>
Error_code List<T>::insert(const T& item)
{
	Node<T>* new_entry = new Node<T>(item);

	if (new_entry == NULL) return overflow;   // IF FULL
	else if (empty())
		head = new_entry;
	else if (item.account_no < head->entry)
	{
		new_entry->next = head;
		head = new_entry;
	}
	else
	{
		Node<T>* previous = head, * current = head->next;

		while (current != NULL)
		{
			if (item.account_no < current->entry.account_no)
			{
				new_entry->next = current;
				break;
			}
			previous = current;
			current = current->next;
		}
		previous->next = new_entry;
	}
	return success;
}

template <class T>
Error_code List<T>::search(T& item) const
{
	Node<T>* temp = head;
	while (temp != NULL)
	{
		if (temp->entry.account_no == item.account_no)
		{
			item = temp->entry;
			return success;
		}
		temp = temp->next;
	}
	return not_found;
}

template <class T>
Error_code List<T>::remove(const T& item)
{
	Node<T>* current = head;
	if (empty()) return underflow;
	if (item.account_no < head->entry.account_no) return not_found;
	if (item.account_no == head->entry.account_no)
	{
		head = head->next;
		delete current;
		return success;
	}
	Node<T>* previous = current;
	current = current->next;
	while (current != NULL)
	{
		if (item.account_no < head->entry.account_no) break;
		if (item.account_no == current->entry.account_no)
		{
			previous->next = current->next;
			delete current;
			return success;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	return not_found;
}

template <class T>
Error_code List<T>::modify(string key, T &item)
{
	Node<T>* temp = head;
	while(temp != NULL)
	{
		if (temp->entry.account_no == item.account_no)
		{
			if (key == WITHDRAW)
				temp->entry.balance -= item.balance;
			else if (key == DEPOSIT)
				temp->entry.balance += item.balance;
			else if (key == UPDATE)
				temp->entry = item;
			return success;
		}
		temp = temp->next;
	}
	return not_found;	
}

// ------- Safeguards ----------

template <class T>
List<T>::~List()
{
	Node<T>* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}


template <class T>
List<T>::List(const List<T>& original)
{
	Node<T>* new_copy, * original_node = original.head;
	if (original_node == NULL) head = NULL;
	else
	{
		head = new_copy = new Node<T>(original_node->entry);
		while (original_node->next != NULL)
		{
			original_node = original_node->next;
			new_copy->next = new Node<T>(original_node->entry);
			new_copy = new_copy->next;
		}
	}
}


template <class T>
void List<T>::operator=(const List<T>& original)
{
	Node<T>* new_head, * new_copy, * original_node = original.head;
	if (original_node == NULL) head = NULL;
	else
	{
		new_copy = new_head = new Node<T>(original_node->entry);
		while (original_node->next != NULL)
		{
			original_node = original_node->next;
			new_copy->next = new Node<T>(original_node->entry);
			new_copy = new_copy->next;
		}
	}
	clear();
	head = new_head;
}


