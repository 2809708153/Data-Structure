#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//链表数据类型
typedef int ElemType;

/*int main() {
	SLinkNode *x;
	InitList(x);

	return 0;
}*/

//定义链表
typedef struct node {
	ElemType data;
	struct node* prior, * next;
}DLinkNode;

//初始化
void InitList(DLinkNode*& L) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
}
//销毁
void DestroyList(DLinkNode*& L) {
	DLinkNode* pre = L, * p = pre->next;
	while (p != NULL) {
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
	while (p != NULL) {
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
	while (p != NULL && j < i) {
		j++;
		p = p->next;
	}
	if (p == NULL)
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
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else
		return j;
}
//插入元素
int InsElem(DLinkNode*& L, ElemType x, int i) {
	int j = 1;
	DLinkNode* p = L->next, * s, * pre;
	if (i <= 0)
		return 0;
	while (p != L && j < i) {
		p = p->next;
		j++;
	}
	if (p == L && i > j + 1)
		return 0;
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = x;
		pre = p->prior;
		s->prior = pre;
		pre->next = s;
		s->next = p->next;
		p->prior = s;
		s->next = p;
		return 1;
	}
}
//删除元素
int DelElem(DLinkNode*& L, int i) {
	int j = 1;
	DLinkNode* p = L->next, * q;
	if (i <= 0)
		return 0;
	if (L->next == L)
		return 0;
	while (p != L && j < i) {
		j++;
		p = p->next;
	}
	if (p == L)
		return 0;
	else {
		q = p->prior;
		p->next->prior = q;
		q->next = p->next;
		q->next = p->next;
		free(p);
		return 1;

	}
}
//输出链表
void DispList(DLinkNode* L) {
	DLinkNode* p = L->next;
	while (p != L) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//反转循环双链表
void Reverse(DLinkNode*& L) {
	DLinkNode* p = L->next, * q;
	L->next = L->prior = L;
	while (p != L) {
		q = p->next;
		p->next = L->next;
		L->next->prior = p;
		L->next = p;
		p->prior = L;
		p = q;
	}
}
//判断循环双链表是否对称
int Symmetric(DLinkNode* L) {
	int flag = 1;
	DLinkNode* p = L->next, * q = L->prior;
	while (flag == 1) {
		if (p->data != q->data)
			flag = 0;
		else {
			if (p == q || p->next == q)
				break;
			p = p->next;
			q = q->prior;
		}
	}
	return flag;
}