#ifndef __SQUEUE_HPP_
#define __SQUEUE_HPP_
#include <cstddef>
#include <cstdlib>
#include <iostream>
template <typename T>
struct QueueNode {
	T val;
	QueueNode* next;
};

template <typename T>
class Queue
{
private:
	std::size_t size;
	QueueNode<T>* head;
	QueueNode<T>* tail;

public:
	Queue();
	Queue(const Queue& st);
	Queue& operator=(const Queue& st);
	bool IsEmpty();
	void enqueue(T& e);
	void dequeue(T& e);
	~Queue();
};

template <typename T>
Queue<T>::Queue()
    : size(0)
    , head(nullptr)
    , tail(nullptr)
{
}

template <typename T>
Queue<T>::Queue(const Queue<T>& st)
{
	*this = st;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& st)
{
	if (this != &st)
	{
		size = st.size;
		QueueNode<T>* pthis = tail;
		QueueNode<T>* pthat = st.tail;
		for (int i = 0; i < size; ++i)
		{
			pthis = new QueueNode<T>{0, nullptr};
			pthis->val = pthat->val;
			pthat = pthat->next;
		}
	}
	return *this;
}

template <typename T>
void Queue<T>::enqueue(T& e)
{
	if (size == 0)
	{
		QueueNode<T>* pqe = new QueueNode<T>{e, this};
		tail = pqe;
		head = pqe;
	}
	else
	{
		QueueNode<T>* pqe = new QueueNode<T>{e, tail};
		head->next = pqe;
		head = pqe;
	}
	++size;
}

template <typename T>
void Queue<T>::dequeue(T& e)
{
	if (IsEmpty())
	{
		std::cout << "Queue is empty" << std::endl;
	}
	else
	{
		e = tail->val;
		QueueNode<T>* tmp = tail;
		tail = tail->next;
		head->next = tail;
		delete tmp;
		--size;
	}
}

template <typename T>
bool Queue<T>::IsEmpty()
{
	return (size);
}

template <typename T>
Queue<T>::~Queue()
{
	T a;
	while (tail)
	{
		dequeue(a);
	}
}

#endif
