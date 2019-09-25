#ifndef __MYRBTREE_HPP__
#define __MYRBTREE_HPP__
#include <cstddef>
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
enum RBColor { RED, BLACK };
template <typename T>
class RBNode
{
public:
	RBColor color;
	T key;
	RBNode* left;
	RBNode* right;
	RBNode* parent;
	RBNode(RBColor _color = BLACK, T _key = 0, RBNode* _left = nullptr, RBNode* _right = nullptr, RBNode* _parent = nullptr) : color(_color), key(_key), left(_left), right(_right), parent(_parent) {}
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
	 * @brief 返回最小值, 空树返回 0
	 */
	T minimum();

	/**
	 * @brief 返回最大值, 空树返回 0
	 */
	T maximum();

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
RBNode<T>* RBTree<T>::copy(RBNode<T>* parent, RBNode<T>* _root)
{
	if (!_root) return nullptr;
	RBNode<T>* ret = new RBNode<T>(_root->color, _root->key, copy(ret, _root->left), copy(ret, _root->right), parent);
}

template <typename T>
RBTree<T>& RBTree<T>::operator=(const RBTree<T>& rbt)
{
	if (this == &rbt) return *this;
	destory(root);
	root = copy(nullptr, rbt.root);
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
	x->right     = y->left;
	if (y->left) y->left->parent = y;
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
	while (root)
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
	else if (z->key < py->key)
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

#endif /* __MYRBTREE_HPP__ */
