#ifndef __BINTREE_H__
#define __BINTREE_H__

struct BitNode {
	int key;
	BitNode* parent;
	BitNode* lchild;
	BitNode* rchild;
	BitNode()
	    : key(0)
	    , parent(nullptr)
	    , lchild(nullptr)
	    , rchild(nullptr)
	{
	}
};

class BinTree
{
private:
	BitNode* root;

public:
	void InorderTreeWalk() const;
  void InorderTreeWalk(const BitNode* r) const;
	void PreorderTreeWalk(const BitNode* r) const;
	void PostorderTreeWalk(const BitNode* r) const;
	void TreeInsert(int e);
	BinTree(int* ar, int n);
	BinTree()
	{
		root = nullptr;
	}
	~BinTree();
};

#endif  //__BINTREE_H__
