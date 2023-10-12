#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//������������
typedef int ElemType;
 
//������������ݽ��
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QType;
//���ӽ�����Ͷ���
typedef struct qptr {
	QType* front;
	QType* rear;
}LinkQueue;

//��ʼ��ջ����
void InitStack(LinkQueue*& lq) {
	lq = (LinkQueue*)malloc(sizeof(LinkQueue));
	lq->front = lq->rear = NULL;
}
//���ٶ�����
void DestroyQueue(LinkQueue*& lq) {
	QType* pre = lq->front, * p;
	if (pre == NULL)
		return;
	if (pre == lq->rear)
		free(pre);
	else {
		p = pre->next;
		while (p) {
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(lq);
}
//����
int EnQueue(LinkQueue* lq, ElemType x) {
	QType* p;
	p = (QType*)malloc(sizeof(QType));
	p->data = x;
	p->next = NULL;
	if (lq->front == NULL)
		lq->rear = lq->front = p;
	else {
		lq->rear->next = p;
		lq->rear = p;
	}
	return 1;
}
//����
int DeQueue(LinkQueue* lq, ElemType& x) {
	QType* p;
	if (lq->front == NULL) {
		return 0;
	}
	else {
		p = lq->front;
		x = p->data;
		if (lq->rear == lq->front)
			lq->rear = lq->front = NULL;
		else
			lq->front = lq->front->next;
		free(p);
		return 1;
	}
}
//ȡ��ͷ
int GetHead(LinkQueue* lq, ElemType& x) {
	if (lq->front == NULL)
		return 0;
	else {
		x = lq->front->data;
		return 1;
	}
}
//�ж϶������
int QueueEmpty(LinkQueue* lq) {
	return lq->front == NULL;
}
