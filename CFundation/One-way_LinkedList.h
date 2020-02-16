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
	//初始化链表
	LinkList Init_LinkList();
	//插入结点
	void Insert_LinkList(LinkList list, int pos, void* data);
	//遍历链表
	void Foreach_LinkList(LinkList list, FOREAH myforeach);

	//按位置删除
	void RemoveByPos_LinkList(LinkList list, int pos);
	//按值删除
	void RemoveByVal_LinkList(LinkList list, void* data, COMPARE compare);
	//清空链表
	void Cleaer_LinkList(LinkList list);
	//大小
	int Size_LinkList(LinkList list);
	//销毁链表
	void Destroy_LinkList(LinkList list);
#ifdef __cplusplus
}
#endif // __cplusplus
