#include "linklist.h"
#include <iostream>

LinkList::LinkList()
  :size(0)
  ,head(nullptr)
{
}

LinkList::LinkList(LinkList const& list)
{
	size = list.size;
	if (size == 0)
	{
		head = nullptr;
	}
	else
	{
		LSingleNode* pthis = head;
		LSingleNode const* plist = list.head;
		while (plist)
		{
			pthis = new LSingleNode;
			pthis->key = plist->key;
			pthis = pthis->next;
			plist = plist->next;
		}
	}
}

LinkList::~LinkList()
{
	LSingleNode* pl = head;
	LSingleNode* pn;
	while (pl)
	{
		pn = pl->next;
		delete pl;
		pl = pn;
	}
}

LSingleNode& LinkList::operator[](std::size_t i)
{
	if (i >= size)
	{
		std::cout << "overflow" << std::endl;
		abort();
	}
	LSingleNode* pl = head;
	for (int n = 0; n < i; n++)
	{
		pl = pl->next;
	}
	return *pl;
}

LSingleNode* LinkList::Search(int key) const
{
	LSingleNode* pl = head;
	while (pl)
	{
		if (pl->key == key)
			return pl;
	}
	return pl;
}

void LinkList::Insert(int i, int key)
{
	if (i >= size)
	{
		std::cout << "overflow, i just insert it in the end of list." << std::endl;
		i = size - 1;
	}
	LSingleNode* pl = new LSingleNode{key, nullptr};
	LSingleNode* pi = head;
	for (int n = 0; n < i; n++)
	{
		pi = pi->next;
	}
	pl->next = pi->next;
	pi->next = pl;
	++size;
}

void LinkList::Insert(int key)
{
	LSingleNode* pl = new LSingleNode{key, nullptr};
	LSingleNode* pi = head;
	while (pi->next)
		pi = pi->next;
	pi->next = pl;
	++size;
}

void LinkList::Delete(int i, int& key)
{
	if (i >= size)
	{
		std::cout << "overflow" << std::endl;
		abort();
	}
	LSingleNode* ppre = new LSingleNode{0, head};
	LSingleNode* pdel = head;
	for (int n = 0; n < i; ++n)
	{
		delete ppre;
		ppre = pdel;
		pdel = pdel->next;
	}
	key = pdel->key;
	ppre->next = pdel->next;
	delete pdel;
	--size;
	if (ppre->next == head)
		delete ppre;
}
