#pragma once
#include <memory>

template <typename T>
struct node
{
	T data;
	node *next;
};

template <typename T>
class LinkedList
{
public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	~LinkedList();
	
	void push_back(const T &element)
	{
		node<T> *temp = new node<T>;
		temp->data = element;
		temp->next = nullptr;
		++length;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
			temp = nullptr;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void push_front(const T &element)
	{
		node *temp = std::unique_ptr<T>;
		temp->data = element;
		temp->next = head;
		head = temp;
		++length;
	}

private:
	node<T> *head, *tail;
	int length;
};