// Edward Brecht
// 12/10/2019

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
	/// <summary>
	/// constructor for linked list
	/// </summary>
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		current = nullptr;
		previous = nullptr;
		length = 0;
	}

	/// <summary>
	/// destructor for linked list
	/// </summary>
	~LinkedList()
	{
		current = head;
		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
			delete previous;
		}
		delete current;
	}
	
	/// <summary>
	/// inserts a node at end of list
	/// </summary>
	/// <param name="element">element</param>
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

	/// <summary>
	/// inserts a node at beginning of list
	/// </summary>
	/// <param name="element">element</param>
	void push_front(const T &element)
	{
		node<T> *newNode = new node<T>;
		newNode->data = element;
		newNode->next = head;
		head = newNode;
		++length;
		
	}

	/// <summary>
	/// inserts a node at desired position
	/// </summary>
	/// <param name="element">element</param>
	/// <param name="position">position</param>
	/// <returns>bool</returns>
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

	/// <summary>
	/// erases node at desired position
	/// </summary>
	/// <param name="position">position</param>
	/// <returns>bool</returns>
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

	/// <summary>
	/// erases first node that matches input data
	/// </summary>
	/// <param name="element">element</param>
	/// <returns>bool</returns>
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

	/// <summary>
	/// returns size of list
	/// </summary>
	/// <returns>length</returns>
	unsigned int size() const
	{
		return length;
	}

	/// <summary>
	/// deletes node in last position
	/// </summary>
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
		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			tail = previous;
			previous->next = nullptr;
		}
		delete current;
		--length;
	}

	/// <summary>
	/// deletes node in first position
	/// </summary>
	void pop_front()
	{
		current = head;
		if (length > 1)
		{
			head = head->next;
		}
		else
		{
			head = nullptr;
			tail = nullptr;
		}
		delete current;
		--length;
	}

	/// <summary>
	/// returns data from desired position.
	/// no bounds checking, and probable memory leak
	/// </summary>
	/// <param name="position">position</param>
	/// <returns>temp->data</returns>
	T& get_element(unsigned int position) const
	{
		node<T> *temp = new node<T>;
		temp = head;
		for (size_t i = 1; i < position; ++i)
		{
			temp = temp->next;
		}
		return temp->data;
	}

	/// <summary>
	/// returns data from first position
	/// </summary>
	/// <returns>head->data</returns>
	T& get_front() const
	{
		return head->data;
	}

	/// <summary>
	/// returns data from last position
	/// </summary>
	/// <returns>tail->data</returns>
	T& get_back() const
	{
		return tail->data;
	}

private:
	node<T> *head, *tail, *current, *previous;
	unsigned int length;
};