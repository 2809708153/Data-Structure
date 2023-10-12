#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//链栈数据类型
typedef int ElemType;


//定义栈链表
typedef struct node {
	ElemType data;
	struct node* next;
}LinkStack;

//初始化栈链表
void InitStack(LinkStack*& ls) {
	ls = NULL;
} 
//销毁栈链表
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
//进栈
int Push(LinkStack* ls,ElemType x) {
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = ls;
	ls = p;
	return 1;
}
//出栈
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
//取栈顶
int GetTop(LinkStack* ls, ElemType &x) {
	if (ls == NULL)
		return 0;
	else {
		x = ls->data;
		return 1;
	}
}
//判断栈链表空
int StackEmpty(LinkStack* ls) {
	return ls == NULL;
}
