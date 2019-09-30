#ifndef __TREAAP_HPP_
#define __TREAP_HPP_
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
template <typename T>
class TreapNode
{
public:
	T key;
	unsigned int priority;
	TreapNode<T>* parent;
	TreapNode<T>* left;
	TreapNode<T>* right;
	TreapNode(T _key, int _priority, TreapNode<T>* _parent = nullptr, TreapNode<T>* _left = nullptr, TreapNode<T>* _right = nullptr)
	    : key(_key), priority(_priority), parent(_parent), left(_left), right(_right){};
};

template <typename T>
class Treap
{
private:
	TreapNode<T>* root;

public:
	Treap() : root(nullptr)
	{
		std::srand(time(nullptr));
	}
	Treap(const Treap<T>& _tree);
	~Treap();
	Treap<T>& operator=(const Treap<T>& _tree);
	TreapNode<T>* itersearch(const T _key) const;
	void insert(T _key);
	void remove(T _key);
	void preOrderView();
	void inOrderView();

private:
	TreapNode<T>* copy(TreapNode<T>* _parent, TreapNode<T>* _root);
	void destory(TreapNode<T>* _root);
	void leftRoate(TreapNode<T>* x);
	void rightRoate(TreapNode<T>* x);
	void insert(TreapNode<T>* z);
	void remove(TreapNode<T>* z);
	void insertFix(TreapNode<T>* z);
	void transSubtree(TreapNode<T>* src, TreapNode<T>* dic);
};

template <typename T>
Treap<T>::Treap(const Treap<T>& rbt)
{
	root = copy(nullptr, rbt.root);
}

template <typename T>
Treap<T>::~Treap()
{
	destory(root);
}

template <typename T>
TreapNode<T>* Treap<T>::copy(TreapNode<T>* _parent, TreapNode<T>* _root)
{
	if (!_root) return nullptr;
	TreapNode<T>* ret = new TreapNode<T>(_root->color, _root->key);
	ret->parent       = _parent;
	ret->left         = copy(ret, _root->left);
	ret->right        = copy(ret, _root->right);
	return ret;
}

template <typename T>
Treap<T>& Treap<T>::operator=(const Treap<T>& rbt)
{
	if (this == &rbt) return *this;
	destory(root);
	root = copy(nullptr, rbt.root);
	return *this;
}

template <typename T>
void Treap<T>::destory(TreapNode<T>* _root)
{
	if (_root)
	{
		TreapNode<T>* _left  = _root->left;
		TreapNode<T>* _right = _root->right;
		delete _root;
		destory(_left);
		destory(_right);
	}
}

template <typename T>
TreapNode<T>* Treap<T>::itersearch(const T _key) const
{
	TreapNode<T>* res = root;
	while (res)
	{
		if (res->key == _key) return res;
		if (_key < res->key)
			res = res->left;
		else
			res = res->right;
	}
	return res;
}

template <typename T>
void Treap<T>::leftRoate(TreapNode<T>* x)
{
	TreapNode<T>* y = x->right;
	x->right        = y->left;
	if (x->right) x->right->parent = x;
	y->parent = x->parent;
	if (!y->parent)
		root = y;
	else if (y->parent->left == x)
		y->parent->left = y;
	else
		y->parent->right = y;
	y->left   = x;
	x->parent = y;
}

template <typename T>
void Treap<T>::rightRoate(TreapNode<T>* x)
{
	TreapNode<T>* y = x->left;
	x->left         = y->right;
	if (x->left) x->left->parent = x;
	y->parent = x->parent;
	if (!y->parent)
		root = y;
	else if (y->parent->left == x)
		y->parent->left = y;
	else
		y->parent->right = y;
	y->right  = x;
	x->parent = y;
}

template <typename T>
void Treap<T>::insert(T _key)
{
	TreapNode<T>* node = new TreapNode<T>(_key, rand());
	insert(node);
}
template <typename T>
void Treap<T>::insert(TreapNode<T>* z)
{
	TreapNode<T>* y = nullptr;
	TreapNode<T>* x = root;
	while (x)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (!y)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	insertFix(z);
}

template <typename T>
void Treap<T>::insertFix(TreapNode<T>* z)
{
	while (z != root && z->priority < z->parent->priority)
	{
		if (z == z->parent->left)
			rightRoate(z->parent);
		else
			leftRoate(z->parent);
	}
}

template <typename T>
void Treap<T>::remove(T _key)
{
	TreapNode<T>* pt = root;
	while (pt)
	{
		if (_key == pt->key) break;
		if (_key < pt->key)
			pt = pt->left;
		else
			pt = pt->right;
	}
	if (pt) remove(pt);
}

template <typename T>
void Treap<T>::remove(TreapNode<T>* z)
{
	while (z->left && z->right)
	{
		if (z->left->priority < z->right->priority)
			rightRoate(z);
		else
			leftRoate(z);
	}
	if (!z->left)
	{
		transSubtree(z, z->right);
	}
	else
	{
		transSubtree(z, z->left);
	}
	delete z;
}

template <typename T>
void Treap<T>::transSubtree(TreapNode<T>* src, TreapNode<T>* dic)
{
	if (!src->parent)
		root = dic;
	else if (src == src->parent->left)
		src->parent->left = dic;
	else
		src->parent->right = dic;
	if (dic) dic->parent = src->parent;
}

template <typename T>
void Treap<T>::preOrderView()
{
	using std::stack;
	TreapNode<T>* pt = root;
	stack<TreapNode<T>*> St;
	while (pt || !St.empty())
	{
		while (pt)
		{
			std::cout << pt->key << ":" << pt->priority << ",";
			St.push(pt);
			pt = pt->left;
		}
		pt = St.top();
		St.pop();
		pt = pt->right;
	}
	std::cout << "\n";
}

template <typename T>
void Treap<T>::inOrderView()
{
	using std::stack;
	TreapNode<T>* pt = root;
	stack<TreapNode<T>*> St;
	while (pt || !St.empty())
	{
		while (pt)
		{
			St.push(pt);
			pt = pt->left;
		}
		pt = St.top();
		St.pop();
		std::cout << pt->key << ":" << pt->priority << ",";
		pt = pt->right;
	}
	std::cout << "\n";
}
#endif /* __TREAP_HPP_ */
