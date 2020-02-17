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
	//初始化栈
	SeqStack stack = Init_SeqStack();
	//先把根节点压入栈中
	Push_SeqStack(stack, createInfo(root, false));
	while (Size_SeqStack(stack)>0) {
		//获得栈顶元素
		struct Info* info = (struct Info*)Top_SeqStack(stack);
		//弹出栈顶元素
		Pop_SeqStack(stack);
		if (info->flag) {
			printf("%c ", info->node->ch);
			free(info);
			continue;
		}
		//将右子树压入栈
		if (info->node->rchild != NULL) {
			Push_SeqStack(stack, createInfo(info->node->rchild, false));
		}
		//将左子树压入栈
		if (info->node->lchild != NULL) {
			Push_SeqStack(stack, createInfo(info->node->lchild, false));
		}
		//将根节点压入栈中
		info->flag = true;
		Push_SeqStack(stack, info);

	}
	//销毁栈
	Destroy_SeqStack(stack);
}