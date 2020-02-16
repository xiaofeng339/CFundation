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
		void* data[MAX];//存放数据的数组
		int size;//栈中元素的个数
	};
	typedef void* SeqStack;
	//数组高下标的位置作为栈顶，因为不需要移动数组中的元素在插入和删除中

	//初始化
	SeqStack* Init_SeqStack();
	//入栈
	void Push_SeqStack(SeqStack stack,void *data);
	//出栈
	void Pop_SeqStack(SeqStack stack);
	//获取栈顶元素
	void* Top_SeqStack(SeqStack stack);
	//获取栈的大小
	int Size_SeqStack(SeqStack stack);
	//销毁栈
	void Destroy_SeqStack(SeqStack stack);
	
#ifdef __cplusplus
}
#endif // __cplusplus
