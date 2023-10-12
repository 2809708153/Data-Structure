#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 100
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;
//³õÊ¼»¯Õ»
void InitList(SqStack*& st) {
	st->top = -1;
}
//Ïú»ÙÕ»
int DestroyList(SqStack*& st) {
	free(st);
	return 1;
}
//½øÕ»
int Push(SqStack*& st, ElemType x) {
	if (st->top = MaxSize - 1)
		return 0;
	else {
		st->top++;
		st->data[st->top] = x;
		return 1;
	}
}
//³öÕ»
int pop(SqStack*& st, ElemType &x) {
	if (st->top == -1)
		return 0;
	else {
		x = st->data[st->top];
		st->top--;
		return 1;
	}
}
//È¡Õ»¶¥ÔªËØ
int GetTop(SqStack* st, ElemType& x) {
	if (st->top == -1)
		return 0;
	else {
		x = st->data[st->top];
		return 1;
	}
}
//ÅÐ¶ÏÕ»¿Õ
int StackEmpty(SqStack* st) {
	return st->top == -1;
}
