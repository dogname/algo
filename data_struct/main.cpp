#include "bittree.hpp"
#include "squeue.hpp"
#include "stack.hpp"
#include "treap.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
	Treap<int> treap;
	for (int i = 0; i < 10; ++i)
	{
		treap.insert(i);
	}
    treap.preOrderView();
    treap.inOrderView();
	for (int i = 0; i < 3; ++i) treap.remove(rand() % 10);
	treap.preOrderView();
	treap.inOrderView();
	return 0;
}
