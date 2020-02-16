#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#define MAX 1024
	struct SStack
	{
		void* data[MAX];//������ݵ�����
		int size;//ջ��Ԫ�صĸ���
	};
	typedef void* SeqStack;
	//������±��λ����Ϊջ������Ϊ����Ҫ�ƶ������е�Ԫ���ڲ����ɾ����

	//��ʼ��
	SeqStack* Init_SeqStack();
	//��ջ
	void Push_SeqStack(SeqStack stack,void *data);
	//��ջ
	void Pop_SeqStack(SeqStack stack);
	//��ȡջ��Ԫ��
	void* Top_SeqStack(SeqStack stack);
	//��ȡջ�Ĵ�С
	int Size_SeqStack(SeqStack stack);
	//����ջ
	void Destroy_SeqStack(SeqStack stack);
	
#ifdef __cplusplus
}
#endif // __cplusplus
