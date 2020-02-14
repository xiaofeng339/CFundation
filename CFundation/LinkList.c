#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include "LinkList.h"


//初始化链表
struct LinkNode* Init_LinkList() {
	//创建头指针
	struct LinkNode* header = malloc(sizeof(struct LinkNode));
	header->data = -1;
	header->next = NULL;

	//尾部指针
	struct LinkNode* pRear =header;
	int val = -1;
	while (1) {
		printf("请输入插入数据：\n");
		scanf("%d", &val);
		if (val == -1) {
			break;
		}
		//先创建新节点
		struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
		newnode->data = val;
		newnode->next = Null;
		//新节点插入到链表中
		pRear->next = newnode;
		//更新尾部指针指向
		pRear = newnode;
		

	}
	return header;


}
//在值为oldval的位置插入一个新的数据newval
void InsertByValue_LinkList(struct LinkNode* header, int oldval, int newval);
//删除值为val的结点
void RemoveByValue_LinkList(struct LinkNode* header, int delValue) {
	if (NULL == header) {
		return;
	}
	//辅助指针变量
	struct  LinkNode* pCurrent = header->next;
	while (pCurrent != NULL)
	{
		printf("%d", pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
//遍历
void Foreach_LinkList(struct LinkNode* header);
//销毁
void Destroy_LinkList(struct LinkNode* header);
//清空
void Clear_LinkList(struct LinkNode* header);