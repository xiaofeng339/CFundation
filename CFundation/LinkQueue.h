#pragma once

//����ڵ����������
struct QueueNode {
	struct QueueNode* next;
};

struct LQueue
{
	struct QueueNode header;//ͷ���
	int size;
	struct QueueNode* rear; //βָ�룬ʼ��ָ����������һ���ڵ�
};

typedef void* LinkQueue;


//��ʼ��
LinkQueue Init_LInkQueue();
//���
void Push_LinkQueue(LinkQueue queue, void* data);
//����
void Pop_LinkQueue(LinkQueue queue);
//��ȡ��ͷԪ��
void* Front_LinkQueue(LinkQueue queue);
//��ȡ��βԪ��
void* Back_LinkQueue(LinkQueue queue);
//��С
int Size_LinkQueue(LinkQueue queue);
//���ٶ���
void Destroy_LinkQueue(LinkQueue queue);
