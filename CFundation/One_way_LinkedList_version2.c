#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	

//链表节点数据结构
struct LinkNode {
	struct LinkNode* next;
};

//链表结构体
struct LList {
	struct LinkNode header;//头结点
	int size;
};

typedef void* LinkList;

//初始化链表
LinkList Init_LinkList() {
	struct LList* list = malloc(sizeof(struct LList));
	if (NULL == list) {
		return NULL;
	}
	list->header.next = NULL;
	list->size = 0;
	return list;
}
void Insert_LinkList(LinkList list, int position, void* data) {
	if (NULL == list) {
		return;
	}
	if (NULL == data) {
		return;
	}
	struct LList* mylist = (struct LList*)list;
	struct LinkNode* mynode = (struct LinkNode*)data;
	if (position <0 || position >mylist->size) {
		position = mylist->size;
	}
	//找到position位置的前一个位置
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < position; ++i) {
		pCurrent = pCurrent->next;
	}
	//数据入链表
	mynode->next = pCurrent->next;
	pCurrent->next = mynode;
	mylist->size++;
}
//遍历
void Foreach_LinkList(LinkList list, void(*foreach)(void*)) {
	if (NULL == list) {
		return;
	}
	if (NULL == foreach) {
		return;
	}
	struct LList* mylist = (struct LList*) list;
	struct LinkNode* pCurrent = &(mylist->header);

	while (pCurrent != NULL) {
		struct LinkNode* pNext = pCurrent->next;
		foreach(pCurrent);
		pCurrent = pNext;
	}
}
//删除结点
void RemoveByPos_LinkList(LinkList list, int position) {
	if (NULL == list) {
		return;
	}
	struct LList* mylist = (struct LList*)list;
	if (position<0 || position>mylist->size - 1) {
		return;
	}
	//辅助指针
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < position; ++i) {
		pCurrent = pCurrent->next;
	}
	//缓存下待删除节点
	struct LinkNode* pDel = pCurrent->next;
	//重新建立删除节点的前驱和后记节点关系
	pCurrent->next = pDel->next;
	mylist->size--;
}

//销毁
void Destroy_LinkList(LinkList list) {
	if (NULL == list) {
		return;
	}
	free(list);
	list = NULL;
}
