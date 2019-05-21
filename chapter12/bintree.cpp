#include "bintree.h"
#include <iostream>
#include <stack>

BinTree::BinTree(int* ar, int n)
    : root(nullptr)
{
	for (int i = 0; i < n; ++i)
	{
		TreeInsert(ar[i]);
	}
}

BinTree::~BinTree()
{
	if (root)
	{
		std::stack<BitNode*> st;
		BitNode* r = root;
		while (r || !st.empty())
		{
			while (r)
			{
					st.push(r);
					r = r->lchild;
			}
			if (!st.empty())
			{
				r = st.top();
				st.pop();
				delete r;
			}
			r = r->rchild;
		}
	}
}

void BinTree::TreeInsert(int e)
{
	if (root == nullptr)
	{
		root = new BitNode;
		root->key = e;
	}
	else
	{
		BitNode* p = root;
		while (1)
		{
			if (e < p->key && p->lchild)
			{
				p = p->lchild;
			}
			else if (e < p->key)
			{
				p->lchild = new BitNode;
				p->lchild->parent = p;
				p->lchild->key = e;
				break;
			}
			else if (p->rchild)
			{
				p = p->rchild;
			}
			else
			{
				p->rchild = new BitNode;
				p->rchild->parent = p;
				p->rchild->key = e;
				break;
			}
		}
	}
}

void BinTree::InorderTreeWalk() const
{  // 非递归, 练习12.1-3
		if (root)
		{
			std::stack<BitNode*> st;
			BitNode* r = root;
			while (r || !st.empty())
			{
				while (r)
				{
						st.push(r);
						r = r->lchild;
				}
				if (!st.empty())
				{
					r = st.top();
					st.pop();
					std::cout << r->key << " ";
				}
				r = r->rchild;
			}
			std::cout << std::endl;
		}
}

void BinTree::InorderTreeWalk(const BitNode * r) const
{
  if(r)
    {
      InorderTreeWalk(r->lchild);
      std::cout << r->key << " ";
      InorderTreeWalk(r->rchild);
    }
}
