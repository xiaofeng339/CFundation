#pragma once

//链表节点的数据类型
struct QueueNode {
	struct QueueNode* next;
};

struct LQueue
{
	struct QueueNode header;//头结点
	int size;
	struct QueueNode* rear; //尾指针，始终指向链表的最后一个节点
};

typedef void* LinkQueue;


//初始化
LinkQueue Init_LInkQueue();
//入队
void Push_LinkQueue(LinkQueue queue, void* data);
//出队
void Pop_LinkQueue(LinkQueue queue);
//获取队头元素
void* Front_LinkQueue(LinkQueue queue);
//获取队尾元素
void* Back_LinkQueue(LinkQueue queue);
//大小
int Size_LinkQueue(LinkQueue queue);
//销毁队列
void Destroy_LinkQueue(LinkQueue queue);
