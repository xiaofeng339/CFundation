#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	

//����ڵ����ݽṹ
struct LinkNode {
	struct LinkNode* next;
};

//����ṹ��
struct LList {
	struct LinkNode header;//ͷ���
	int size;
};

typedef void* LinkList;

//��ʼ������
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
	//�ҵ�positionλ�õ�ǰһ��λ��
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < position; ++i) {
		pCurrent = pCurrent->next;
	}
	//����������
	mynode->next = pCurrent->next;
	pCurrent->next = mynode;
	mylist->size++;
}
//����
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
//ɾ�����
void RemoveByPos_LinkList(LinkList list, int position) {
	if (NULL == list) {
		return;
	}
	struct LList* mylist = (struct LList*)list;
	if (position<0 || position>mylist->size - 1) {
		return;
	}
	//����ָ��
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < position; ++i) {
		pCurrent = pCurrent->next;
	}
	//�����´�ɾ���ڵ�
	struct LinkNode* pDel = pCurrent->next;
	//���½���ɾ���ڵ��ǰ���ͺ�ǽڵ��ϵ
	pCurrent->next = pDel->next;
	mylist->size--;
}

//����
void Destroy_LinkList(LinkList list) {
	if (NULL == list) {
		return;
	}
	free(list);
	list = NULL;
}
