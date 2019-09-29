#pragma once

 /*
  * ˫�������ڵ�
  */
typedef struct listNode {

	// ǰ�ýڵ�
	struct listNode *prev;

	// ���ýڵ�
	struct listNode *next;

	// �ڵ��ֵ
	void *value;

} listNode;

/*
 * ˫������������
 */
typedef struct listIter {

	// ��ǰ�������Ľڵ�
	listNode *next;

	// �����ķ���
	int direction;

} listIter;

/*
 * ˫�������ṹ
 */
typedef struct list {

	// ��ͷ�ڵ�
	listNode *head;

	// ��β�ڵ�
	listNode *tail;

	// �ڵ�ֵ���ƺ���
	void *(*dup)(void *ptr);

	// �ڵ�ֵ�ͷź���
	void(*free)(void *ptr);

	// �ڵ�ֵ�ԱȺ���
	int(*match)(void *ptr, void *key);

	// �����������Ľڵ�����
	unsigned long len;

} list;

/* Functions implemented as macros */
// ���ظ��������������Ľڵ�����
// T = O(1)
#define listLength(l) ((l)->len)
// ���ظ��������ı�ͷ�ڵ�
// T = O(1)
#define listFirst(l) ((l)->head)
// ���ظ��������ı�β�ڵ�
// T = O(1)
#define listLast(l) ((l)->tail)
// ���ظ����ڵ��ǰ�ýڵ�
// T = O(1)
#define listPrevNode(n) ((n)->prev)
// ���ظ����ڵ�ĺ��ýڵ�
// T = O(1)
#define listNextNode(n) ((n)->next)
// ���ظ����ڵ��ֵ
// T = O(1)
#define listNodeValue(n) ((n)->value)

// ������ l ��ֵ���ƺ�������Ϊ m
// T = O(1)
#define listSetDupMethod(l,m) ((l)->dup = (m))
// ������ l ��ֵ�ͷź�������Ϊ m
// T = O(1)
#define listSetFreeMethod(l,m) ((l)->free = (m))
// �������ĶԱȺ�������Ϊ m
// T = O(1)
#define listSetMatchMethod(l,m) ((l)->match = (m))

// ���ظ���������ֵ���ƺ���
// T = O(1)
#define listGetDupMethod(l) ((l)->dup)
// ���ظ���������ֵ�ͷź���
// T = O(1)
#define listGetFree(l) ((l)->free)
// ���ظ���������ֵ�ԱȺ���
// T = O(1)
#define listGetMatchMethod(l) ((l)->match)

/* Prototypes */
list *listCreate(void);
void listRelease(list *list);
list *listAddNodeHead(list *list, void *value);
list *listAddNodeTail(list *list, void *value);
list *listInsertNode(list *list, listNode *old_node, void *value, int after);
void listDelNode(list *list, listNode *node);
listIter *listGetIterator(list *list, int direction);
listNode *listNext(listIter *iter);
void listReleaseIterator(listIter *iter);
list *listDup(list *orig);
listNode *listSearchKey(list *list, void *key);
listNode *listIndex(list *list, long index);
void listRewind(list *list, listIter *li);
void listRewindTail(list *list, listIter *li);
void listRotate(list *list);

/* Directions for iterators
 *
 * ���������е����ķ���
 */
 // �ӱ�ͷ���β���е���
#define AL_START_HEAD 0
// �ӱ�β����ͷ���е���
#define AL_START_TAIL 1
