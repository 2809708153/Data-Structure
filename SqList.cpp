#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 
#define MaxSize 100
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;
//初始化顺序表
int InitList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
	return 1;
}
//销毁顺序表
int DestroyList(SqList*& L) {
	free(L);
	return 1;
}
//重置顺序表
int ClearList(SqList*& L) {
	int i;
	for (i = 0; i < L->length; i++) {
		L->data[i] = 0;
	}
	L->length = 0;
	return 1;
}
//判断是否为空
int ListEmpty(SqList* L) {
	if (L->length == 0)
		return 1;
	return 0;
}
//求顺序表长度
int ListLength(SqList* L) {
	return L->length;
}
//按索引查找
int GetElem(SqList* L, int i, ElemType& e) {
	if (i<1 || i>L->length)
		return 0;
	else {
		e = L->data[i - 1];
		return 1;
	}
}
//按值查找
int LocateElem(SqList*& L, int i, ElemType& e) {
	int j;
	for (j = 0; j < L->length; j++)
		if (L->data[j] == i) {
			e = j + 1;
			return 1;
		}
	return 0;
}
//寻找上一个元素
int PriorElem(SqList* L, ElemType cur_e, ElemType* pre_e) {
	int i;
	for (i = 2; i <= L->length; i++) {
		if (L->data[i - 1] == cur_e) {
			*pre_e = L->data[i - 2];
			return 1;
		}
		else continue;
	}//从第二个元素开始找，若有与cur_e相等的数据元素，将其前驱的值赋给pre_e并返回   
	return 0;
}
//寻找下一个元素
int NextElem(SqList* L, ElemType cur_e, ElemType* next_e) {
	int i;
	for (i = 1; i < L->length; i++) {
		if (L->data[i - 1] == cur_e) {
			*next_e = L->data[i];
			return 1;
		}//从第一个元素开始找，一直到倒数第二个元素，若有与cur_e相等的数据元素，将其后继的值赋给pre_e并返回 
		else continue;
	}
	return 0;
}
//按索引插入
int InsElem(SqList*& L, int i, int e) {
	if (i<1 || i>L->length+1)
		return 0;
	int j;
	for (j = L->length; j > i - 1; j--)
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = e;
	L->length++;
	return 1;
}
//按索引删除
int DelElem(SqList*& L, ElemType i, int& e) {
	if (i<1 || i>L->length)
		return 0;
	int j, k = 0;
	e = L->data[i - 1];
	for (j = 0; j < L->length; j++) {
		if (j != i - 1) {
			L->data[k] = L->data[j];
			k++;
		}
	}
	L->length = k;
	return 1;
}
//输出顺序表
void DispList(SqList* L) {
	int i;
	for (i = 0; i < L->length; i++)
		cout << L->data[i] << " ";
	cout << endl;
}
//创建顺序表
void CreateList(SqList*& L, ElemType* a, int n) {
	L = (SqList*)malloc(sizeof(SqList));
	int i, k = 0;
	for (i = 0; i < n; i++) {
		L->data[k++] = a[i];
	}
	L->length = k;
}
//奇数移到偶数前
void Move(SqList*& L) {
	int i = 0, j = L->length - 1;
	while (i < j) {
		while (L->data[i] & 1)
			i++;
		while (!(L->data[j] & 1))
			j--;
		if (i < j) {
			ElemType t = L->data[i];
			L->data[i] = L->data[j];
			L->data[j] = t;
		}
	}
}
//二路归并
void Merge(SqList* A, SqList* B, SqList*& C) {
	int i = 0, j = 0, k = 0;
	while (i < A->length && j < B->length) {
		if (A->data[i] < B->data[j]) {
			C->data[k] = A->data[i];
			i++;
			k++;
		}
		else {
			C->data[i] = B->data[j];
			j++;
			k++;
		}
	}
	while (i < A->length) {
		C->data[k] = A->data[i];
		i++;
		k++;
	}
	while (j < B->length) {
		C->data[k] = B->data[j];
		j++;
		k++;
	}
	C->length = k;
}
//顺序表操作函数
void PrintMenu() {
	cout << "输入相应序号完成对应操作：\n";
	cout << "1:线性表重置为空                       "; cout << "2:判断是否为空\n";
	cout << "3:求线性表的长度                       "; cout << "4:求线性表元素值\n";
	cout << "5:求线性表元素位置                     "; cout << "6:求前驱元素的值\n";
	cout << "7:求后继元素的值                       "; cout << "8:插入新的数据元素\n";
	cout << "9:删除数据元素                         "; cout << "10:输出整个线性表\n";
	cout << "0:结束操作\n";
}





int main() {
	system("title 顺序表操作");
	SqList* L;
	int i, n, e;
	cout << "程序启动\n";
	cout << "初始化新的顺序表L......\n";
	if (InitList(L))
		cout << "初始化成功\n";
	else
		cout << "初始化失败\n";
	cout << "输入元素个数n：";
	cin >> n;
	cout << "输入" << n << "个数据元素(元素间以空格间隔)：";
	int temp;
	for (i = 1; i <= n; i++) {
		cin >> temp;
		InsElem(L, i, temp);
	}
	PrintMenu();
	while (1) {
		cout << "请输入您的操作序号：";
		string choice;
		cin >> choice;
		if (choice == "1") {
			if (ClearList(L))
				cout << "重置线性表L成功" << endl;
			else
				cout << "重置线性表L失败" << endl;
		}
		else if (choice == "2") {
			if (ListEmpty(L))
				cout << "线性表L为空" << endl;
			else
				cout << "线性表L不为空" << endl;
		}
		else if (choice == "3") {
			cout << "该线性表的长度为：" << ListLength(L) << endl;
		}
		else if (choice == "4") {
			cout << "请输入您要查找元素序号：" << endl;
			cin >> i;
			if (GetElem(L, i, e)) {
				cout << "线性表第" << i << "个元素为：" << e << endl;
			}
			else
				cout << "您输入的i不成立" << endl;
		}
		else if (choice == "5") {
			cout << "请输入您要查找元素：" << endl;
			cin >> i;
			if (LocateElem(L, i, e)) {
				cout << "线性表第" << i << "个元素为：" << e << endl;
			}
			else
				cout << "查找不到该元素" << endl;
		}
		else if (choice == "6") {
			cout << "请输入您要查找的元素：" << endl;
			ElemType cur_e, pre_e;
			cin >> cur_e;
			if (PriorElem(L, cur_e, &pre_e)) {
				cout << "该元素的前驱元素为" << pre_e << endl;
			}
			else
				cout << "输入元素不存在或没有前驱元素" << endl;
		}
		else if (choice == "7") {
			cout << "请输入您要查找的元素：" << endl;
			ElemType cur_e, next_e;
			cin >> cur_e;
			if (NextElem(L, cur_e, &next_e)) {
				cout << "该元素的后继元素为" << next_e << endl;
			}
			else
				cout << "输入元素不存在或没有后继元素" << endl;
		}
		else if (choice == "8") {
			cout << "请输入插入位置：";
			cin >> i;
			cout << "请输入插入数据元素";
			cin >> e;
			if (InsElem(L, i, e)) {
				cout << "插入成功" << endl;
			}
			else
				cout << "插入失败" << endl;
		}
		else if (choice == "9") {
			cout << "请输入删除序号";
			cin >> i;
			if (DelElem(L, i, e)) {
				cout << "删除成功!" << " 您删除的元素是" << e << endl;
			}
			else
				cout << "删除失败" << endl;
		}
		else if (choice == "10") {
			DispList(L);
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
