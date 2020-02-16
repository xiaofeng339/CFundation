#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	
	typedef void* LinkList;
	typedef void(*FOREAH)(void*);
	typedef int(*COMPARE)(void*, void*);
	//��ʼ������
	LinkList Init_LinkList();
	//������
	void Insert_LinkList(LinkList list, int pos, void* data);
	//��������
	void Foreach_LinkList(LinkList list, FOREAH myforeach);

	//��λ��ɾ��
	void RemoveByPos_LinkList(LinkList list, int pos);
	//��ֵɾ��
	void RemoveByVal_LinkList(LinkList list, void* data, COMPARE compare);
	//�������
	void Cleaer_LinkList(LinkList list);
	//��С
	int Size_LinkList(LinkList list);
	//��������
	void Destroy_LinkList(LinkList list);
#ifdef __cplusplus
}
#endif // __cplusplus
