#pragma once
#include "IStack.h"
#include "ExceptionNullPtr.h"

template <typename T>
struct Node
{
	T data; 
	Node* next;
	Node(T data_, Node* ptr = 0) :data(data_), next(ptr) {}
};

template <typename T>
class StackOnList : public IStack<T>
{
	Node<T>* top;
public:
	StackOnList();
	~StackOnList();
	bool isEmpty();
	void push(const T value);
	T pop();
};

template<typename T>
inline StackOnList<T>::StackOnList()
{
	top = nullptr;
}

template<typename T>
inline StackOnList<T>::~StackOnList()
{
	while (!isEmpty())
	{
		pop();
	}
}

template<typename T>
inline bool StackOnList<T>::isEmpty()
{
	return !top;
}

template<typename T>
inline void StackOnList<T>::push(const T value)
{
	top = new Node<T>(value, top);
}

template<typename T>
inline T StackOnList<T>::pop()
{
	try
	{ 
		if (!top)
			throw ExceptionNullPtr("Error: dereferencing a null pointer");
		T result = top->data;
		Node<T>* cur = top;
		top = cur->next;
		delete cur;
		cur = nullptr;
		return result;
	}
	catch(ExceptionNullPtr e)
	{
		std::cerr << e.what();
	}
}
