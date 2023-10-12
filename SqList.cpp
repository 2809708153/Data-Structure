#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 
#define MaxSize 100
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;
//��ʼ��˳���
int InitList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
	return 1;
}
//����˳���
int DestroyList(SqList*& L) {
	free(L);
	return 1;
}
//����˳���
int ClearList(SqList*& L) {
	int i;
	for (i = 0; i < L->length; i++) {
		L->data[i] = 0;
	}
	L->length = 0;
	return 1;
}
//�ж��Ƿ�Ϊ��
int ListEmpty(SqList* L) {
	if (L->length == 0)
		return 1;
	return 0;
}
//��˳�����
int ListLength(SqList* L) {
	return L->length;
}
//����������
int GetElem(SqList* L, int i, ElemType& e) {
	if (i<1 || i>L->length)
		return 0;
	else {
		e = L->data[i - 1];
		return 1;
	}
}
//��ֵ����
int LocateElem(SqList*& L, int i, ElemType& e) {
	int j;
	for (j = 0; j < L->length; j++)
		if (L->data[j] == i) {
			e = j + 1;
			return 1;
		}
	return 0;
}
//Ѱ����һ��Ԫ��
int PriorElem(SqList* L, ElemType cur_e, ElemType* pre_e) {
	int i;
	for (i = 2; i <= L->length; i++) {
		if (L->data[i - 1] == cur_e) {
			*pre_e = L->data[i - 2];
			return 1;
		}
		else continue;
	}//�ӵڶ���Ԫ�ؿ�ʼ�ң�������cur_e��ȵ�����Ԫ�أ�����ǰ����ֵ����pre_e������   
	return 0;
}
//Ѱ����һ��Ԫ��
int NextElem(SqList* L, ElemType cur_e, ElemType* next_e) {
	int i;
	for (i = 1; i < L->length; i++) {
		if (L->data[i - 1] == cur_e) {
			*next_e = L->data[i];
			return 1;
		}//�ӵ�һ��Ԫ�ؿ�ʼ�ң�һֱ�������ڶ���Ԫ�أ�������cur_e��ȵ�����Ԫ�أ������̵�ֵ����pre_e������ 
		else continue;
	}
	return 0;
}
//����������
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
//������ɾ��
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
//���˳���
void DispList(SqList* L) {
	int i;
	for (i = 0; i < L->length; i++)
		cout << L->data[i] << " ";
	cout << endl;
}
//����˳���
void CreateList(SqList*& L, ElemType* a, int n) {
	L = (SqList*)malloc(sizeof(SqList));
	int i, k = 0;
	for (i = 0; i < n; i++) {
		L->data[k++] = a[i];
	}
	L->length = k;
}
//�����Ƶ�ż��ǰ
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
//��·�鲢
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
//˳����������
void PrintMenu() {
	cout << "������Ӧ�����ɶ�Ӧ������\n";
	cout << "1:���Ա�����Ϊ��                       "; cout << "2:�ж��Ƿ�Ϊ��\n";
	cout << "3:�����Ա�ĳ���                       "; cout << "4:�����Ա�Ԫ��ֵ\n";
	cout << "5:�����Ա�Ԫ��λ��                     "; cout << "6:��ǰ��Ԫ�ص�ֵ\n";
	cout << "7:����Ԫ�ص�ֵ                       "; cout << "8:�����µ�����Ԫ��\n";
	cout << "9:ɾ������Ԫ��                         "; cout << "10:����������Ա�\n";
	cout << "0:��������\n";
}





int main() {
	system("title ˳������");
	SqList* L;
	int i, n, e;
	cout << "��������\n";
	cout << "��ʼ���µ�˳���L......\n";
	if (InitList(L))
		cout << "��ʼ���ɹ�\n";
	else
		cout << "��ʼ��ʧ��\n";
	cout << "����Ԫ�ظ���n��";
	cin >> n;
	cout << "����" << n << "������Ԫ��(Ԫ�ؼ��Կո���)��";
	int temp;
	for (i = 1; i <= n; i++) {
		cin >> temp;
		InsElem(L, i, temp);
	}
	PrintMenu();
	while (1) {
		cout << "���������Ĳ�����ţ�";
		string choice;
		cin >> choice;
		if (choice == "1") {
			if (ClearList(L))
				cout << "�������Ա�L�ɹ�" << endl;
			else
				cout << "�������Ա�Lʧ��" << endl;
		}
		else if (choice == "2") {
			if (ListEmpty(L))
				cout << "���Ա�LΪ��" << endl;
			else
				cout << "���Ա�L��Ϊ��" << endl;
		}
		else if (choice == "3") {
			cout << "�����Ա�ĳ���Ϊ��" << ListLength(L) << endl;
		}
		else if (choice == "4") {
			cout << "��������Ҫ����Ԫ����ţ�" << endl;
			cin >> i;
			if (GetElem(L, i, e)) {
				cout << "���Ա��" << i << "��Ԫ��Ϊ��" << e << endl;
			}
			else
				cout << "�������i������" << endl;
		}
		else if (choice == "5") {
			cout << "��������Ҫ����Ԫ�أ�" << endl;
			cin >> i;
			if (LocateElem(L, i, e)) {
				cout << "���Ա��" << i << "��Ԫ��Ϊ��" << e << endl;
			}
			else
				cout << "���Ҳ�����Ԫ��" << endl;
		}
		else if (choice == "6") {
			cout << "��������Ҫ���ҵ�Ԫ�أ�" << endl;
			ElemType cur_e, pre_e;
			cin >> cur_e;
			if (PriorElem(L, cur_e, &pre_e)) {
				cout << "��Ԫ�ص�ǰ��Ԫ��Ϊ" << pre_e << endl;
			}
			else
				cout << "����Ԫ�ز����ڻ�û��ǰ��Ԫ��" << endl;
		}
		else if (choice == "7") {
			cout << "��������Ҫ���ҵ�Ԫ�أ�" << endl;
			ElemType cur_e, next_e;
			cin >> cur_e;
			if (NextElem(L, cur_e, &next_e)) {
				cout << "��Ԫ�صĺ��Ԫ��Ϊ" << next_e << endl;
			}
			else
				cout << "����Ԫ�ز����ڻ�û�к��Ԫ��" << endl;
		}
		else if (choice == "8") {
			cout << "���������λ�ã�";
			cin >> i;
			cout << "�������������Ԫ��";
			cin >> e;
			if (InsElem(L, i, e)) {
				cout << "����ɹ�" << endl;
			}
			else
				cout << "����ʧ��" << endl;
		}
		else if (choice == "9") {
			cout << "������ɾ�����";
			cin >> i;
			if (DelElem(L, i, e)) {
				cout << "ɾ���ɹ�!" << " ��ɾ����Ԫ����" << e << endl;
			}
			else
				cout << "ɾ��ʧ��" << endl;
		}
		else if (choice == "10") {
			DispList(L);
		}
		else if (choice == "0") {
			cout << "���ڽ�������..." << endl;
			break;
		}
		else {
			cout << "����Ƿ�������������..." << endl;
		}
	}
	cout << "���������������˳�ϵͳ..." << endl;
	return 0;
}
