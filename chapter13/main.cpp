#include "myrbtree.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
	int a[20] = {1, 2, 3, 4, 123, 23, 2341, 123, 5344, 1231, 353, 123, 53, 1231, 3452, 123, 33, 321, 344, 123};
	RBTree<int> rbTree;
	for (int i = 0; i < 20; ++i)
	{
		rbTree.insert(a[i]);
	}
    rbTree.inOrder();
    rbTree.preOrder();
    rbTree.remove(1);
    rbTree.remove(123);
    rbTree.inOrder();
    rbTree.preOrder();
	return 0;
}
