#pragma once

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
		current = nullptr;
		previous = nullptr;
		length = 0;
	}

	~LinkedList();
	
	void push_back(const T &element)
	{
		node<T> *newNode = new node<T>;
		newNode->data = element;
		newNode->next = nullptr;
		++length;
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
			newNode = nullptr;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		
	}

	void push_front(const T &element)
	{
		node<T> *newNode = new node<T>;
		newNode->data = element;
		newNode->next = head;
		head = newNode;
		++length;
		
	}

bool insert(const T &element, unsigned int position)
{
	// check for valid position
	if ((position < 1) || (position > (length + 1)))
	{
		return false;
	}
	else
	{
		// if inserting at beginning or end use  proper functions
		if (position == 1)
		{
			push_front(element);
			return true;
		}
		if (position == length + 1)
		{
			push_back(element);
			return true;
		}


		node<T> *newNode = new node<T>;
		current = head;
		// cycle to desired position
		for (size_t i = 1; i < position; ++i)
		{
			previous = current;
			current = current->next;
		}
		// insert at desired position
		newNode->data = element;
		previous->next = newNode;
		newNode->next = current;
		++length;
		return true;
	}
	return false;
}

bool erase(unsigned int position)
{
	// check for valid position
	if ((position < 1) || (position > (length + 1)))
	{
		return false;
	}
	else
	{
		current = head;
		// cycle to desired position
		for (size_t i = 1; i < position; ++i)
		{
			previous = current;
			current = current->next;
		}
		// establish new link and delete node
		previous->next = current->next;
		delete current;
		--length;
		return true;
	}
	return false;
}

bool erase(const T &element)
{
	current = head;
	for (size_t i = 1; i <= length; ++i)
	{
		if (current->data == element)
		{
			// delete from front
			if (i == 1)
			{
				head = current->next;
				delete current;
				--length;
				return true;
			}
			// delete from back
			else if (i == length)
			{
				tail = previous;
				previous->next = nullptr;
				delete current;
				--length;
				return true;
			}
			// delete from other position
			else
			{
				previous->next = current->next;
				delete current;
				--length;
				return true;
			}
		}
		previous = current;
		current = current->next;
	}
	return false;
}

unsigned int size() const
{
	return length;
}

void pop_back()
{
	current = head;
	// cycle to end
	for (size_t i = 1; i < length; ++i)
	{
		previous = current;
		current = current->next;
	}
	// delete node
	tail = previous;
	previous->next = nullptr;
	delete current;
	--length;
}

void pop_front()
{
	current = head;
	head = head->next;
	delete current;
	--length;
}

private:
	node<T> *head, *tail, *current, *previous;
	unsigned int length;
};