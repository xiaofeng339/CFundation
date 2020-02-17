#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include"LinkQueue.h"
//��ʼ��
LinkQueue Init_LInkQueue() {
	struct LQueue* queue = malloc(sizeof(struct LQueue));
	if (NULL == queue) {
		return;
	}
	queue->header.next = NULL;
	queue->size = 0;
	queue->rear = &(queue->header);
	return queue;
}
//���
void Push_LinkQueue(LinkQueue queue, void* data) {
	if (NULL == queue) {
		return;
	}
	if (NULL == data) {
		return;
	}
	struct LQueue* q = (struct LQueue*) queue;
	struct QueueNode* n = (struct QueueNode*)data;
	q->rear->next = n;
	n->next = NULL;
	//����βָ��
	q->rear = n;
	q->size++;
}
//����
void Pop_LinkQueue(LinkQueue queue) {
	if (NULL == queue) {
		return;
	}
	struct LQueue* q = (struct LQueue*) queue;
	if (q->size == 0) {
		return;
	}
	if (q->size == 1) {
		q->header.next = NULL;
		q->rear = &(q->header);
		q->size--;
		return;
	}
	struct QueueNode* pFirstNode = q->header.next;
	q->header.next = pFirstNode->next;
	q->size--;

}
//��ȡ��ͷԪ��
void* Front_LinkQueue(LinkQueue queue) {
	if (NULL == queue) {
		return;
	}
	struct LQueue* q = (struct LQueue*) queue;
	return q->header.next;
}
//��ȡ��βԪ��
void* Back_LinkQueue(LinkQueue queue) {
	if (NULL == queue) {
		return;
	}
	struct LQueue* q = (struct LQueue*) queue;
	return q->rear;
}
//��С
int Size_LinkQueue(LinkQueue queue) {
	if (NULL == queue) {
		return;
	}
	struct LQueue* q = (struct LQueue*) queue;
	return q->size;
}
//���ٶ���
void Destroy_LinkQueue(LinkQueue queue) {
	if (NULL == queue) {
		return;
	}
	free(queue);
	queue = NULL;
}