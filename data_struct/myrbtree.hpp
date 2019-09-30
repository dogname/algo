#ifndef __MYRBTREE_HPP__
#define __MYRBTREE_HPP__
#include <cstddef>
#include <iostream>
#include <stack>
/**
 *  @brief 红黑树节点
 *
 *  红黑树的节点满足一下性质
 *  1. 每个节点的 color 属性为 black(黑), 或 red (红)
 *  2. 根节点为黑
 *  3. 空叶子节点为黑
 *  4. 红色节点的孩子是黑色
 *  5. 从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点
 *
 */
enum RBColor
{
	RED,
	BLACK
};
template <typename T>
class RBNode
{
public:
	RBColor color;
	T key;
	RBNode* left;
	RBNode* right;
	RBNode* parent;
	RBNode(RBColor _color = BLACK, T _key = 0, RBNode* _left = nullptr, RBNode* _right = nullptr, RBNode* _parent = nullptr)
	    : color(_color), key(_key), left(_left), right(_right), parent(_parent)
	{
	}
};

/**
 *  @brief 红黑树
 */

template <typename T>
class RBTree
{
private:
	RBNode<T>* root;

public:
	RBTree() : root(nullptr) {}
	~RBTree();
	RBTree(const RBTree<T>& rbt);
	RBTree<T>& operator=(const RBTree<T>& rbt);
	/**
	 *  @brief 查找键值为 k 的节点, 递归
	 *  @param key 关键字
	 *  @return  RBNode*
	 */
	RBNode<T>* search(T key);

	/**
	 *  @brief 查找键值为 k 的节点, 非递归
	 *  @param key 关键字
	 *  @return  RBNode*
	 */
	RBNode<T>* iterSearch(T key);

	/**
	 * @brief 插入节点
	 */
	void insert(T key);

	/**
	 * @brief 删除节点
	 */
	void remove(T key);

	/**
	 * @brief 查找节点 x (有右孩子) 的后继节点
	 */
	RBNode<T>* successor(RBNode<T>* x);

	/**
	 * @brief 返回最小值, 空树返回 0
	 */
	T minimum();

	/**
	 * @brief 返回最大值, 空树返回 0
	 */
	T maximum();

	/**
	 * @brief 中序遍历
	 */
	void inOrder() const;

	/**
	 * @breif 前序遍历
	 */
	void preOrder() const;

private:
	/**
	 * @brief 递归的拷贝函数
	 */
	RBNode<T>* copy(RBNode<T>* parent, RBNode<T>* _root);

	/**
	 * 递归删除树
	 */
	void destory(RBNode<T>* _root);

	/**
	 * @brief 左旋
	 */
	void leftRoate(RBNode<T>* x);

	/**
	 *  @brief 右旋
	 */
	void rightRoate(RBNode<T>* x);

	RBNode<T>* search(RBNode<T>* _root, T key) const;

	void insertFix(RBNode<T>* z);

	void transSubtree(RBNode<T>* src, RBNode<T>* dic);

	void removeFix(RBNode<T>* x);

	void remove(RBNode<T>* z);
};

template <typename T>
RBTree<T>::RBTree(const RBTree<T>& rbt)
{
	root = copy(nullptr, rbt.root);
}

template <typename T>
RBTree<T>::~RBTree()
{
	destory(root);
}

template <typename T>
RBNode<T>* RBTree<T>::copy(RBNode<T>* _parent, RBNode<T>* _root)
{
	if (!_root) return nullptr;
	RBNode<T>* ret = new RBNode<T>(_root->color, _root->key);
	ret->parent    = _parent;
	ret->left      = copy(ret, _root->left);
	ret->right     = copy(ret, _root->right);
	return ret;
}

template <typename T>
RBTree<T>& RBTree<T>::operator=(const RBTree<T>& rbt)
{
	if (this == &rbt) return *this;
	destory(root);
	root = copy(nullptr, rbt.root);
	return *this;
}

template <typename T>
RBNode<T>* RBTree<T>::search(T key)
{
	return search(root, key);
}

template <typename T>
RBNode<T>* RBTree<T>::search(RBNode<T>* _root, T key) const
{
	if (!_root) return nullptr;
	if (key == _root->key) return _root;
	if (key < _root->key) return search(_root->left, key);
	if (key > _root->key) return search(_root->right, key);
}

template <typename T>
RBNode<T>* RBTree<T>::iterSearch(T key)
{
	RBNode<T>* pt = root;
	while (pt)
	{
		if (key == pt->key) return pt;
		if (key < pt->key)
			pt = pt->left;
		else if (key > pt->key)
			pt = pt->right;
	}
	return pt;
}

template <typename T>
void RBTree<T>::destory(RBNode<T>* _root)
{
	if (_root)
	{
		RBNode<T>* _left  = _root->left;
		RBNode<T>* _right = _root->right;
		delete _root;
		destory(_left);
		destory(_right);
	}
}

template <typename T>
RBNode<T>* RBTree<T>::successor(RBNode<T>* x)
{
	RBNode<T>* ret = x->right;
	while (ret->left)
	{
		ret = ret->left;
	}
	return ret;
}

template <typename T>
T RBTree<T>::minimum()
{
	if (!root) return 0;
	RBNode<T>* pt = root;
	while (pt->left) pt = pt->left;
	return pt->key;
}

template <typename T>
T RBTree<T>::maximum()
{
	if (!root) return 0;
	RBNode<T>* pt = root;
	while (pt->right) pt = pt->right;
	return pt->key;
}

template <typename T>
void RBTree<T>::leftRoate(RBNode<T>* x)
{
	RBNode<T>* y = x->right;
	x->right     = y->left;
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
void RBTree<T>::rightRoate(RBNode<T>* x)
{
	RBNode<T>* y = x->left;
	x->left      = y->right;
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
void RBTree<T>::insert(T key)
{
	RBNode<T>* z  = new RBNode<T>(RED, key, nullptr, nullptr, nullptr);
	RBNode<T>* px = root;
	RBNode<T>* py = nullptr;
	while (px)
	{
		py = px;
		if (key < px->key)
			px = px->left;
		else
			px = px->right;
	}
	z->parent = py;
	if (!py)
		root = z;
	else if (key < py->key)
		py->left = z;
	else
		py->right = z;
	insertFix(z);
}

template <typename T>
void RBTree<T>::insertFix(RBNode<T>* z)
{
	while (z->parent && z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			RBNode<T>* uncle = z->parent->parent->right;
			if (uncle && uncle->color == RED)
			{
				uncle->color             = BLACK;
				z->parent->color         = BLACK;
				z->parent->parent->color = RED;
				z                        = z->parent->parent;
				continue;
			}
			else if (z == z->parent->right)
			{
				z = z->parent;
				leftRoate(z);
			}
			z->parent->color         = BLACK;
			z->parent->parent->color = RED;
			rightRoate(z->parent->parent);
		}
		else
		{
			RBNode<T>* uncle = z->parent->parent->left;
			if (uncle && uncle->color == RED)
			{
				uncle->color             = BLACK;
				z->parent->color         = BLACK;
				z->parent->parent->color = RED;
				z                        = z->parent->parent;
				continue;
			}
			else if (z == z->parent->left)
			{
				z = z->parent;
				rightRoate(z);
			}
			z->parent->color         = BLACK;
			z->parent->parent->color = RED;
			leftRoate(z->parent->parent);
		}
	}
	root->color = BLACK;
}

template <typename T>
void RBTree<T>::transSubtree(RBNode<T>* src, RBNode<T>* dic)
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
void RBTree<T>::remove(T key)
{
	RBNode<T>* pt = root;
	while (pt)
	{
		if (key == pt->key) break;
		if (key < pt->key)
			pt = pt->left;
		else
			pt = pt->right;
	}
	if (pt) remove(pt);
}

template <typename T>
void RBTree<T>::remove(RBNode<T>* z)
{
	RBNode<T>* y = z;
	RBNode<T>* x;
	RBColor yOriginalCol = y->color;
	if (!z->left)
	{
		x = z->right;
		transSubtree(z, x);
	}
	else if (!z->right)
	{
		x = z->left;
		transSubtree(z, x);
	}
	else
	{
		y            = successor(z);
		yOriginalCol = y->color;
		x            = y->right;
		if (y->parent == z)
			x->parent = y;
		else
		{
			transSubtree(y, x);
			y->right         = z->right;
			y->right->parent = y;
		}
		transSubtree(z, y);
		y->left         = z->left;
		y->left->parent = y;
	}
	delete z;
	if (yOriginalCol == BLACK) removeFix(x);
}

template <typename T>
void RBTree<T>::removeFix(RBNode<T>* x)
{
	if (x != root && x->color == BLACK)
	{
		if (x == x->parent->left)
		{
			RBNode<T>* brother = x->parent->right;
			if (brother->color == RED)
			{
				brother->color   = BLACK;
				x->parent->color = RED;
				leftRoate(x->parent);
				brother = x->parent->right;
			}
			if (brother->left->color == BLACK && brother->right->color == BLACK)
			{
				brother->color = RED;
				x              = x->parent;
			}
			else if (brother->right->color == BLACK)
			{
				brother->left->color = BLACK;
				brother->color       = RED;
				rightRoate(brother);
				brother = x->parent->right;
			}
			brother->color        = x->parent->color;
			x->parent->color      = BLACK;
			brother->right->color = BLACK;
			leftRoate(x->parent);
			x = root;
		}
		else
		{
			RBNode<T>* brother = x->parent->left;
			if (brother->color == RED)
			{
				brother->color   = BLACK;
				x->parent->color = RED;
				rightRoate(x->parent);
				brother = x->parent->left;
			}
			if (brother->left->color == BLACK && brother->right->color == BLACK)
			{
				brother->color = RED;
				x              = x->parent;
			}
			else if (brother->left->color == BLACK)
			{
				brother->right->color = BLACK;
				brother->color        = RED;
				leftRoate(brother);
				brother = x->parent->left;
			}
			brother->color       = x->parent->color;
			x->parent->color     = BLACK;
			brother->left->color = BLACK;
			rightRoate(x->parent);
			x = root;
		}
	}
	x->color = BLACK;
}
template <typename T>
void RBTree<T>::preOrder() const
{
	using std::cout;
	using std::endl;
	using std::stack;
	stack<RBNode<T>*> St;
	RBNode<T>* pt = root;
	while (pt || !St.empty())
	{
		while (pt)
		{
			cout << pt->key << ",";
			St.push(pt);
			pt = pt->left;
		}
		pt = St.top();
		St.pop();
		pt = pt->right;
	}
	cout << endl;
}

template <typename T>
void RBTree<T>::inOrder() const
{
	using std::cout;
	using std::endl;
	using std::stack;
	stack<RBNode<T>*> St;
	RBNode<T>* pt = root;
	while (pt || !St.empty())
	{
		while (pt)
		{
			St.push(pt);
			pt = pt->left;
		}
		pt = St.top();
		cout << pt->key << ",";
		St.pop();
		pt = pt->right;
	}
	cout << endl;
}

#endif /* __MYRBTREE_HPP__ */
