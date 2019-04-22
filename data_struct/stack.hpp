#ifndef __STACK_HPP_
#define __STACK_HPP_
#include <cstddef>
#include <iostream>
template <typename T>
struct StackNode {
	T val;
	StackNode* next;
};

template <typename T>
class Stack
{
private:
	std::size_t size;
	StackNode<T>* top;

public:
	Stack();
	Stack(const Stack& st);
	Stack& operator=(const Stack& st);
	bool IsEmpty();
	void push(T& e);
	void pop(T& e);
	~Stack();
};

template <typename T>
Stack<T>::Stack()
    : size(0)
    , top(nullptr)
{
}

template <typename T>
Stack<T>::Stack(const Stack<T>& st)
{
	*this = st;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st)
{
	if (this != &st)
	{
		size = st.size;
		StackNode<T>* pthis = top;
		StackNode<T>* pthat = st.top;
		while (pthat)
		{
			pthis = new StackNode<T>{0, nullptr};
			pthis->val = pthat->val;
			pthis = pthis->next;
			pthat = pthat->next;
		}
	}
	return *this;
}

template <typename T>
void Stack<T>::push(T& e)
{
	StackNode<T>* pst = new StackNode<T>{e, top->next};
	top = pst;
}

template <typename T>
void Stack<T>::pop(T& e)
{
	if (IsEmpty())
	{
		std::cout << "Stack is empty" << std::endl;
	}
	else
	{
		e = top->val;
		StackNode<T> tmp = top;
		top = top->next;
		delete tmp;
	}
}

template <typename T>
bool Stack<T>::IsEmpty()
{
	return (!top);
}

#endif
