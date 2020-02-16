#pragma once
#include<stdlib.h>
struct StackNode
{
	struct StackNode* next;
};

struct LStack
{
	struct StackNode header;//ͷ���
	int size;
};

typedef void* LinkStack;

//��ʼ��
LinkStack Init_LinkStack();
//��ջ
void Pust_LinkStack(LinkStack stack, void* data);
//��ջ
void Pop_LinkStack(LinkStack stack);
//��ȡջ��Ԫ��
void* Top_LinkStack(LinkStack stack);
//��ȡ��С
int Size_LInkStack(LinkStack stack);
//����ջ
void Destroy_LinkStack(LinkStack stack);
