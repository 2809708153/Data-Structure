#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//链表数据类型
typedef int ElemType;  


//定义链表
typedef struct node {
	ElemType data;
	struct node* next;
}LinkNode;

//初始化
void InitList(LinkNode *& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
} 
//销毁
void DestroyList(LinkNode*& L) {
	LinkNode* pre = L, * p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}
//求长度
int GetLength(LinkNode*L) {
	int i = 0;
	LinkNode* p = L->next;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
//求第i个元素
int GetElem(LinkNode* L, int i, ElemType& e) {
	int j = 0;
	LinkNode* p = L;
	if (i <= 0)
		return 0;
	while (p != NULL && j<i) {
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
int Locate(LinkNode* L, ElemType e) {
	LinkNode* p = L->next;
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
int InsElem(LinkNode*& L, int i, ElemType x) {
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0)
		return 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}
//删除元素
int DelElem(LinkNode*& L, int i) {
	int j = 0;
	LinkNode* p = L, * q;
	while (p != NULL && j < i - 1) {
		j++;
		p = p->next;
	}
	if (p == NULL) 
		return 0;
	else {
		q = p->next;
		if (q == NULL)
			return 0;
		else {
			p->next = q->next;
			free(q);
			return 1;
		}
	}
}
//输出链表
void DispList(LinkNode* L) {
	LinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//头插法，整体创建链表
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
//尾插法，整体创建链表
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
//链表反转
void Reverse(LinkNode*& L) {
	LinkNode* p = L->next, * q;
	L->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
//奇数移到偶数前
void Movel(LinkNode*& L) {
	LinkNode* p = L->next, * q, * tc;
	L->next = NULL;
	tc = L;
	while (p != NULL) {
		if (p->data & 1) {
			q = p->next;
			if (L->next == NULL) {
				p->next = L->next;
				L->next = p;
				tc = p;
			}
			else {
				p->next = L->next;
				L->next = p;
			}
			p = q;
		}
		else {
			tc->next = p;
			tc = p;
			p = p->next;
		}
	}
	tc->next = NULL;
}
//二路归并
void Merge(LinkNode* ha, LinkNode* hb, LinkNode*& hc) {
	LinkNode* pa = ha->next, * pb = hb->next, * tc;
	hc = ha;
	tc = hc;
	free(hb);
	while (pa != NULL && pb != NULL) {
		if (pa->data < pb->data) {
			tc->next = pa;
			tc = pa;
			pa = pa->next;
		}
		else if (pa->data> pa->data){
			tc->next = pb;
			tc = pb;
			pb = pb->next;
		}
	}
	tc->next = NULL;
	if (pa != NULL)
		tc->next = pa;
	if (pb != NULL)
		tc->next = pb;
}
//顺序表操作函数
void PrintMenu() {
	cout << "输入相应序号完成对应操作：\n";
	cout << "1:头插法建链表                       ";   cout << "2:尾插法建链表\n";
	cout << "3:求单链表长度                       ";   cout << "4:按索引求值\n";
	cout << "5:求数据元素位置                     ";   cout << "6:插入新数据元素e\n";
	cout << "7:删除单链表结点                     ";   cout << "8:输出单链表\n";
	cout << "9:销毁单链表                         ";   cout << "0:结束操作\n";
}

int main() {
	system("title 单链表操作");
	LinkNode* L;
	int i, n, e, arr[1000];
	cout << "程序启动\n";
	cout << "初始化新的顺序表L......\n";
	InitList(L);
	cout << "初始化成功\n";
	cout << "输入元素个数n：";
	cin >> n;
	cout << "输入导入数组的" << n << "个数据元素(元素间以空格间隔)：";
	i = 0;
	do {
		cin >> arr[i++];
	} while (i < n);
	PrintMenu();
	while (1) {
		cout << "请输入您的操作序号：";
		string choice;
		cin >> choice;
		if (choice == "1") {
			CreateListF(L, arr, n);
			cout << "头插法建表成功，输出单链表" << endl;
			DispList(L);
		}
		else if (choice == "2") {
			CreateListR(L, arr, n);
			cout << "尾插法建表成功，输出单链表" << endl;
			DispList(L);
		}
		else if (choice == "3") {
			cout << "该单链表的长度为：" << GetLength(L) << endl;
		}
		else if (choice == "4") {
			cout << "请输入您要查找元素序号：" << endl;
			cin >> i;
			if (GetElem(L, i, e)) {
				cout << "单链表第" << i << "个元素为：" << e << endl;
			}
			else
				cout << "您输入的i不成立" << endl;
		}
		else if (choice == "5") {
			cout << "请输入您要查找元素：" << endl;
			cin >> e;
			if (Locate(L, e)) {
				cout << "单链表第" << Locate(L, e) << "个元素为：" << e << endl;
			}
			else
				cout << "查找不到该元素" << endl;
		}
		else if (choice == "6") {
			cout << "请输入插入位置：";
			cin >> i;
			cout << "请输入插入数据元素：";
			cin >> e;
			if (InsElem(L, i, e)) {
				cout << "插入成功" << endl;
			}
			else
				cout << "插入失败" << endl;
		}
		else if (choice == "7") {
			cout << "请输入删除序号：";
			cin >> i;
			if (DelElem(L, i)) {
				cout << "删除成功!"<< endl;
			}
			else
				cout << "删除失败" << endl;
		}
		else if (choice == "8") {
			DispList(L);
		}
		else if (choice == "9") {
			DestroyList(L);
			cout << "销毁单链表成功" << endl;
		}
		else if (choice == "0") {
			cout << "正在结束操作..." << endl;
			break;
		}
		else {
			cout << "输入非法，请重新输入..." << endl;
		}
	}
	cout << "操作结束，正在退出系统..." << endl;
	return 0;
}