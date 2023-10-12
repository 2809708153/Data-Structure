#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//��ջ��������
typedef int ElemType;


//����ջ����
typedef struct node {
	ElemType data;
	struct node* next;
}LinkStack;

//��ʼ��ջ����
void InitStack(LinkStack*& ls) {
	ls = NULL;
} 
//����ջ����
void DestroyList(LinkStack*& ls) {
	LinkStack* pre = ls, * p;
	if (pre == NULL)
		return;
	p = pre->next;
	while (p) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}
//��ջ
int Push(LinkStack* ls,ElemType x) {
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = ls;
	ls = p;
	return 1;
}
//��ջ
int pop(LinkStack* ls, ElemType& x) {
	LinkStack* p;
	if (ls == NULL) {
		return 0;
	}
	else {
		p = ls;
		x = p->data;
		ls = p->next;
		free(p);
		return 1;
	}
}
//ȡջ��
int GetTop(LinkStack* ls, ElemType &x) {
	if (ls == NULL)
		return 0;
	else {
		x = ls->data;
		return 1;
	}
}
//�ж�ջ�����
int StackEmpty(LinkStack* ls) {
	return ls == NULL;
}
