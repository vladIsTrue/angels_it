#pragma once

template <typename T>
class IStack
{
protected:
	virtual ~IStack() = default;
public:
	virtual bool isEmpty() = 0;
	virtual void push(const T value) = 0;
	virtual T pop() = 0;
};