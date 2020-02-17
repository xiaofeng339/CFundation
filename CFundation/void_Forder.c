#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include<stdbool.h>
#include"SeqStack.h"

struct BiNode {
	char ch;
	struct BiNode* lchild;
	struct BiNode* rchild;
};
struct Info {
	struct BiNode* node;
	bool flag;
};
struct Info* createInfo(struct BiNode* node, bool flag) {
	struct Info* info = malloc(sizeof(struct Info));
	info->flag = flag;
	info->node = node;
	 
}
void nonRecursion(struct BiNode* root) {
	//��ʼ��ջ
	SeqStack stack = Init_SeqStack();
	//�ȰѸ��ڵ�ѹ��ջ��
	Push_SeqStack(stack, createInfo(root, false));
	while (Size_SeqStack(stack)>0) {
		//���ջ��Ԫ��
		struct Info* info = (struct Info*)Top_SeqStack(stack);
		//����ջ��Ԫ��
		Pop_SeqStack(stack);
		if (info->flag) {
			printf("%c ", info->node->ch);
			free(info);
			continue;
		}
		//��������ѹ��ջ
		if (info->node->rchild != NULL) {
			Push_SeqStack(stack, createInfo(info->node->rchild, false));
		}
		//��������ѹ��ջ
		if (info->node->lchild != NULL) {
			Push_SeqStack(stack, createInfo(info->node->lchild, false));
		}
		//�����ڵ�ѹ��ջ��
		info->flag = true;
		Push_SeqStack(stack, info);

	}
	//����ջ
	Destroy_SeqStack(stack);
}