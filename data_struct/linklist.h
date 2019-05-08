#ifndef __LINKLIST_H_
#define __LINKLIST_H_
#include <cstddef>
#include <cstdlib>
struct LSingleNode {
	int key;
	LSingleNode* next;
};

class LinkList
{
private:
	std::size_t size;
	LSingleNode* head;

public:
	LinkList();
	LinkList(const LinkList& list);
	LSingleNode* Search(int key) const;
	LSingleNode& operator[](std::size_t i);
	/**
	 * @breif 插入
	 * @param param i 插入 i 号元素的后面
	 */
	void Insert(int i, int key);
	void Insert(int key);
	void Delete(int i, int& key);
	~LinkList();
};
#endif  // __LINKLIST_H_
