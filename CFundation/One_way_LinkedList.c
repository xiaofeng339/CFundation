#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include"One-way_LinkedList.h"

//��������������
struct LinkNode {
	void* data;
	struct LinkNode* next;
};
//������������
struct LList
{
	struct LinkNode header;
	int size;
};
//��ʼ������
LinkList Init_LinkList() {
	struct LList* list = malloc(sizeof(struct LList));
	if (NULL == list) {
		return NULL;
	}
	list->header.data = NULL;
	list->header.next = NULL;
	return list;
}
//������
void Insert_LinkList(LinkList list, int pos, void* data) {
	if (NULL == list) {
		return;
	}
	if (NULL == data) {
		return;
	}
	struct LList* mylist = (struct LList*)list;
	if (pos<0 || pos>mylist->size) {
		pos = mylist->size;
	}
	//���Ҳ����λ��
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < pos; ++i) {
		pCurrent = pCurrent->next;
	}
	//�����½ڵ�
	struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;
	//�½ڵ���뵽������
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	mylist->size++;

}


//��������
void Foreach_LinkList(LinkList list, FOREAH myforeach) {
	if (NULL == list) {
		return;
	}
	if (NULL ==myforeach)
	{
		return;
	}
	struct LList* mylist = (struct LList*)list;
	struct LinkNode* pCurrent = mylist->header.next;
	while (pCurrent != NULL) {
		myforeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//��λ��ɾ��
void RemoveByPos_LinkList(LinkList list, int pos) {
	if (NULL == list) {
		return;
	}
	struct LList* mylist = (struct LList*)list;
	if (pos<0 || pos>mylist->size - 1) {
		return;
	}
	//��λ��
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < pos; ++i) {
		pCurrent = pCurrent->next;
	}
	//�����ɾ�����
	struct LinkNode* pDel = pCurrent->next;
	//���½�����ɾ������ǰ���ͺ�ǽ���ϵ
	pCurrent->next = pDel->next;
	//�ͷ�ɾ���ڵ��ڴ�
	free(pDel);
	pDel = NULL;
	mylist->size--;
}
//��ֵɾ��
void RemoveByVal_LinkList(LinkList list, void* data, COMPARE compare) {
	if (NULL == list) {
		return;
	}
	if (NULL == data) {
		return;
	}
	if (NULL == compare) {
		return;
	}
	struct LList* mylist = (struct LList*) list;

	//����ָ�����
	struct LinkNode* pPrev = &(mylist->header);
	struct LinkNode* pCurrent = pPrev->next;

	while (pCurrent != NULL) {
		if (compare(pCurrent->data, data)) {
			//�ҵ���
			pPrev->next = pCurrent->next;
			//�ͷ�ɾ���ڵ��ڴ�
			free(pCurrent);
			pCurrent = NULL;
			mylist->size--;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}
//�������
void Cleaer_LinkList(LinkList list) {
	if (NULL == list) {
		return;
	}
	struct LList* mylist = (struct LList*)list;
	//����ָ�����
	struct LinkNode* pCurrent = mylist->header.next;
	while (pCurrent != NULL) {
		//�Ȼ�����һ���ڵ��ַ
		struct LinkNode* pNext = pCurrent->next;
		//�ͷŵ�ǰ����ڴ�
		free(pCurrent);
		pCurrent = pNext;
	}
	mylist->size = 0;
}
//��С
int Size_LinkList(LinkList list) {
	if (NULL == list) {
		return;
	}
	struct LList* mylist = (struct LList*)list;
	return mylist->size;
}
//��������
void Destroy_LinkList(LinkList list) {
	if (NULL == list) {
		return;
	}
	Cleaer_LinkList(list);
	free(list);
	list = NULL;
}
