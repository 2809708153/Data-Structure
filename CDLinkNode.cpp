#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//链表数据类型
typedef int ElemType;
 

//定义链表
typedef struct node {
	ElemType data;
	struct node* prior, * next;
}DLinkNode;

//初始化
void InitList(DLinkNode*& L) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = L;
}
//销毁
void DestroyList(DLinkNode*& L) {
	DLinkNode* pre = L, * p = pre->next;
	while (p != L) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}
//求长度
int GetLength(DLinkNode* L) {
	int i = 0;
	DLinkNode* p = L->next;
	while (p != L) {
		i++;
		p = p->next;
	}
	return i;
}
//求第i个元素
int GetElem(DLinkNode* L, int i, ElemType& e) {
	int j = 0;
	DLinkNode* p = L;
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
//按值查找
int Locate(DLinkNode* L, ElemType e) {
	DLinkNode* p = L->next;
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
//插入元素
int InsElem(DLinkNode*& L, ElemType x, int i) {
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0)
		return 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = x;
		s->next = p->next;
		if (p->next != NULL) {
			p->next->prior = s;
		}
		s->prior = s;
		p->next = s;
		return 1;
	}
}
//删除元素
int DelElem(DLinkNode*& L, int i) {
	int j = 0;
	DLinkNode* p = L, * q;
	if (i <= 0)
		return 0;
	while (p != NULL && j < i) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else {
		q = p->prior;
		if (p->next != NULL) {
			p->next->prior = q;
		}
		q->next = p->next;
		free(p);
		return 1;

	}
}
//输出链表
void DispList(DLinkNode* L) {
	DLinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//头插法，整体创建链表
void CreateListF(DLinkNode*& L, ElemType* a, int n) {
	DLinkNode* s;
	int i;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = NULL;
	for (i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		s->prior = L;
		if (L->next != NULL) {
			L->next->prior = s;
		}
		L->next = s;
	}
}
//尾插法，整体创建链表
void CreateListR(DLinkNode*& L, ElemType* a, int n) {
	DLinkNode* s, * tc;
	int i;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	tc = L;
	for (i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		tc->next = s;
		s->prior = tc;
		tc = s;
	}
	tc->next = NULL;
}