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
		newnode->next = Null;
		//�½ڵ���뵽������
		pRear->next = newnode;
		//����β��ָ��ָ��
		pRear = newnode;
		

	}
	return header;


}
//��ֵΪoldval��λ�ò���һ���µ�����newval
void InsertByValue_LinkList(struct LinkNode* header, int oldval, int newval);
//ɾ��ֵΪval�Ľ��
void RemoveByValue_LinkList(struct LinkNode* header, int delValue) {
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
void Foreach_LinkList(struct LinkNode* header);
//����
void Destroy_LinkList(struct LinkNode* header);
//���
void Clear_LinkList(struct LinkNode* header);