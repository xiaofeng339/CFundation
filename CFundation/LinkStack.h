#pragma once
#include<stdlib.h>
struct StackNode
{
	struct StackNode* next;
};

struct LStack
{
	struct StackNode header;//头结点
	int size;
};

typedef void* LinkStack;

//初始化
LinkStack Init_LinkStack();
//入栈
void Pust_LinkStack(LinkStack stack, void* data);
//出栈
void Pop_LinkStack(LinkStack stack);
//获取栈顶元素
void* Top_LinkStack(LinkStack stack);
//获取大小
int Size_LInkStack(LinkStack stack);
//销毁栈
void Destroy_LinkStack(LinkStack stack);
