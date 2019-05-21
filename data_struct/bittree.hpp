#ifndef __BITTREE_HPP_
#define __BITTREE_HPP_
template <typename T>
struct BTNode {
	T val;
	BTNode* parent;
	BTNode* lchlid;
	BTNode* rchild;
};

template <typename T>
class BitTree
{
private:
  BTNode<T> * root;
public:
  BitTree();
  BitTree(const BitTree &Bt);
  BitTree & operator=(const BitTree &Bt);
  ~BitTree();

};

#endif
