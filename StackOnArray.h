#pragma once
#include "IStack.h"

template <typename T>
class StackOnArray :public IStack<T>
{
	int top;
	const int MAX_SIZE_STACK = 1000;
	T** stack;
public:
	StackOnArray();
	~StackOnArray();
	bool isEmpty();
	void push(const T value);
	T pop();
};

template<typename T>
inline StackOnArray<T>::StackOnArray() : top(-1)
{
	stack = new T * [MAX_SIZE_STACK] {nullptr};
}

template<typename T>
inline StackOnArray<T>::~StackOnArray()
{
	for (int i = 0; i <= top; ++i)
	{
		delete stack[i];
		stack[i] = nullptr;
	}

	delete[] stack;
	stack = nullptr;
}

template<typename T>
inline bool StackOnArray<T>::isEmpty()
{
	return !stack[0];
}

template<typename T>
inline void StackOnArray<T>::push(const T value)
{
	stack[++top] = new T(value);
}

template<typename T>
inline T StackOnArray<T>::pop()
{
	T result = *stack[top];
	delete stack[top];
	stack[top--] = nullptr;
	return result;
}
