#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include "LinkList.h"


//��ʼ������
struct LinkNode* Init_LinkList() {
	//����ͷָ��
	struct LinkNode* header = malloc(sizeof(struct LinkNode));
	header->data = -1;
	header->next = NULL;

	//β��ָ��
	struct LinkNode* pRear =header;
	int val = -1;
	while (1) {
		printf("������������ݣ�\n");
		scanf("%d", &val);
		if (val == -1) {
			break;
		}
		//�ȴ����½ڵ�
		struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
		newnode->data = val;
		newnode->next = NULL;
		//�½ڵ���뵽������
		pRear->next = newnode;
		//����β��ָ��ָ��
		pRear = newnode;
		

	}
	return header;


}
//��ֵΪoldval��λ�ò���һ���µ�����newval
void InsertByValue_LinkList(struct LinkNode* header, int oldval, int newval) {
	if (NULL == header) {
		return;
	}
	//��������ָ�����
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent = pPrev->next;

	while (pCurrent != NULL) {
		if (pCurrent->data == oldval) {
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
#if 0
	if (pCurrent == NULL) {
		return;
	}
#endif
	//�ȴ����½��,��ʼ��
	struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
	newnode->data = newval;
	newnode->next = NULL;

	//�½ڵ���뵽������
	newnode->next = pCurrent;
	pPrev->next = newnode;
}
//ɾ��ֵΪval�Ľ��
void RemoveByValue_LinkList(struct LinkNode* header, int delValue) {
	if (NULL == header) {
		return;
	}

	//��������ָ�����
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent = pPrev->next;

	while (pCurrent != NULL) {
		if (pCurrent->data == delValue) {
			break;
			//pPrev->next = pCurrent->next;
			//free(pCurrent);
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	if (NULL == pCurrent) {
		return;
	}
	//���½�����ɾ���ڵ��ǰ���ͺ�̽ڵ��ϵ
	pPrev->next = pCurrent->next;
	//�ͷ�ɾ���ڵ���ڴ�
	free(pCurrent);
	pCurrent = NULL;
}
//����
void Foreach_LinkList(struct LinkNode* header) {
	if (NULL == header) {
		return;
	}
	//����ָ�����
	struct  LinkNode* pCurrent = header->next;
	while (pCurrent != NULL)
	{
		printf("%d", pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
//����
void Destroy_LinkList(struct LinkNode* header) {
	if (NULL == header) {
		return;
	}
	//����ָ�����
	struct LinkNode* pCurrent = header;
	while (pCurrent !=NULL)
	{
		//�ȱ��浱ǰ�ڵ����һ���ڵ��ַ
		struct LinkNode* pNext = pCurrent->next;
		//�ͷŵ�ǰ���
		free(pCurrent);
		//����ƶ�
		pCurrent = pNext;
	}
}
//���
void Clear_LinkList(struct LinkNode* header) {
	if (NULL == header) {
		return;
	}

	//����ָ�����
	struct LinkNode* pCurrent = header->next;
	while (pCurrent != NULL) {
		//�ȱ����µ�ǰ�ڵ����һ���ڵ��ַ
		struct LinkNode* pNext = pCurrent->next;
		//�ͷŵ�ǰ����ڴ�
		free(pCurrent);
		//pCurrent ָ����һ���ڵ�
		pCurrent = pNext;
	}

}
//��������
void Reverse_LinkList(struct LinkNode* header) {
	if (NULL == header) {
		return;
	}
	struct LinkNode* pPrev = NULL;
	struct LinkNode* pCurrent = header->next;
	struct LinkNode* pNext = NULL;

	while (pCurrent !=NULL)
	{
		pNext = pCurrent->next;
		pCurrent->next = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	header->next = pPrev;
}