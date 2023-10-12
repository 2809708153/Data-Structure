#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//������������
typedef int ElemType;

/*int main() {
	SLinkNode *x;
	InitList(x);

	return 0;
}*/

//��������
typedef struct node {
	ElemType data;
	struct node* next;
}LinkNode;



//��ʼ��
void InitList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = L;
}
//����
void DestroyList(LinkNode*& L) {
	LinkNode* pre = L, * p = pre->next;
	while (p != L) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}
//�󳤶�
int GetLength(LinkNode* L) {
	int i = 0;
	LinkNode* p = L->next;
	while (p != L) {
		i++;
		p = p->next;
	}
	return i;
}
//���i��Ԫ��
int GetElem(LinkNode* L, int i, ElemType& e) {
	int j = 1;
	LinkNode* p = L->next;
	if (i <= 0)
		return 0;
	while (p != L && j < i) {
		j++;
		p = p->next;
	}
	if (p == L)
		return 0;
	else {
		e = p->data;
		return 1;
	}
}
//��ֵ����
int Locate(LinkNode* L, ElemType e) {
	LinkNode* p = L->next;
	int j = 1;
	while (p != L && p->data != e) {
		p = p->next;
		j++;
	}
	if (p == L)
		return 0;
	else
		return j;
}
//����Ԫ��
int InsElem(LinkNode*& L, ElemType x, int i) {
	int j = 1;
	LinkNode* pre = L, * p = pre->next, * s;
	if (i <= 0)
		return 0;
	while (p != L && j < i) {
		pre = p;
		p = p->next;
		j++;
	}
	if (p == L && i > j + 1)
		return 0;
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = x;
		s->next = pre->next;
		pre->next = s;
		return 1;
	}
}
//ɾ��Ԫ��
int DelElem(LinkNode*& L, int i) {
	int j = 0;
	LinkNode* p = L, * q;
	if (i <= 0)
		return 0;
	while (p->next != L && j < i - 1) {
		j++;
		p = p->next;
	}
	if (p->next == L)
		return 0;
	else {
		q = p->next;
		if (q == L)
			return 0;
		else {
			p->next = q->next;
			free(q);
			return 1;
		}
	}
}
//�������
void DispList(LinkNode* L) {
	LinkNode* p = L->next;
	while (p != L) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//ͷ�巨�����崴������
void CreateListF(LinkNode*& L, ElemType* a, int n) {
	LinkNode* s;
	int i;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
//β�巨�����崴������
void CreateListR(LinkNode*& L, ElemType* a, int n) {
	LinkNode* s, * tc;
	int i;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	tc = L;
	for (i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		tc->next = s;
		tc = s;
	}
	tc->next = NULL;
}