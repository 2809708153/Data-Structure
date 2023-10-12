#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 20
typedef int ElemType;
 
typedef struct {
	ElemType data[MaxSize];
	int front, rear;   //�������β
} SqQueue;
//��ʼ����
void InitList(SqQueue*& sq) {
	sq->front = sq->rear = 0;
}
//���ٶ�
int DestroyQueue(SqQueue*& sq) {
	free(sq);
	return 1;
}
//����
int EnQueue(SqQueue*& sq, ElemType x) {
	if ((sq->rear+1)%MaxSize==sq->front)
		return 0;
	else {
		sq->rear = (sq->rear + 1) % MaxSize;
		sq->data[sq->rear] = x;
		return 1;
	}
}
//����
int DeQueue(SqQueue*& sq, ElemType& x) {
	if (sq->front == sq->rear)
		return 0;
	else {
		sq->front= (sq->front + 1) % MaxSize;
		x = sq->data[sq->front];
		return 1;
	}
}
//ȡ��ͷԪ��
int GetHead(SqQueue* sq, ElemType& x) {
	if (sq->front == sq->rear)
		return 0;
	else {
		x = sq->data[(sq->front + 1) % MaxSize];
		return 1;
	}
}
//�ж϶ӿ�
int QueueEmpty(SqQueue* sq) {
	return sq->front == sq->rear;
}
