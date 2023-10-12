#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//������������
typedef int ElemType;  


//��������
typedef struct node {
	ElemType data;
	struct node* next;
}LinkNode;

//��ʼ��
void InitList(LinkNode *& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
} 
//����
void DestroyList(LinkNode*& L) {
	LinkNode* pre = L, * p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}
//�󳤶�
int GetLength(LinkNode*L) {
	int i = 0;
	LinkNode* p = L->next;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
//���i��Ԫ��
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
//��ֵ����
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
//����Ԫ��
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
//ɾ��Ԫ��
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
//�������
void DispList(LinkNode* L) {
	LinkNode* p = L->next;
	while (p != NULL) {
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
//����ת
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
//�����Ƶ�ż��ǰ
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
//��·�鲢
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
//˳����������
void PrintMenu() {
	cout << "������Ӧ�����ɶ�Ӧ������\n";
	cout << "1:ͷ�巨������                       ";   cout << "2:β�巨������\n";
	cout << "3:��������                       ";   cout << "4:��������ֵ\n";
	cout << "5:������Ԫ��λ��                     ";   cout << "6:����������Ԫ��e\n";
	cout << "7:ɾ����������                     ";   cout << "8:���������\n";
	cout << "9:���ٵ�����                         ";   cout << "0:��������\n";
}

int main() {
	system("title ���������");
	LinkNode* L;
	int i, n, e, arr[1000];
	cout << "��������\n";
	cout << "��ʼ���µ�˳���L......\n";
	InitList(L);
	cout << "��ʼ���ɹ�\n";
	cout << "����Ԫ�ظ���n��";
	cin >> n;
	cout << "���뵼�������" << n << "������Ԫ��(Ԫ�ؼ��Կո���)��";
	i = 0;
	do {
		cin >> arr[i++];
	} while (i < n);
	PrintMenu();
	while (1) {
		cout << "���������Ĳ�����ţ�";
		string choice;
		cin >> choice;
		if (choice == "1") {
			CreateListF(L, arr, n);
			cout << "ͷ�巨����ɹ������������" << endl;
			DispList(L);
		}
		else if (choice == "2") {
			CreateListR(L, arr, n);
			cout << "β�巨����ɹ������������" << endl;
			DispList(L);
		}
		else if (choice == "3") {
			cout << "�õ�����ĳ���Ϊ��" << GetLength(L) << endl;
		}
		else if (choice == "4") {
			cout << "��������Ҫ����Ԫ����ţ�" << endl;
			cin >> i;
			if (GetElem(L, i, e)) {
				cout << "�������" << i << "��Ԫ��Ϊ��" << e << endl;
			}
			else
				cout << "�������i������" << endl;
		}
		else if (choice == "5") {
			cout << "��������Ҫ����Ԫ�أ�" << endl;
			cin >> e;
			if (Locate(L, e)) {
				cout << "�������" << Locate(L, e) << "��Ԫ��Ϊ��" << e << endl;
			}
			else
				cout << "���Ҳ�����Ԫ��" << endl;
		}
		else if (choice == "6") {
			cout << "���������λ�ã�";
			cin >> i;
			cout << "�������������Ԫ�أ�";
			cin >> e;
			if (InsElem(L, i, e)) {
				cout << "����ɹ�" << endl;
			}
			else
				cout << "����ʧ��" << endl;
		}
		else if (choice == "7") {
			cout << "������ɾ����ţ�";
			cin >> i;
			if (DelElem(L, i)) {
				cout << "ɾ���ɹ�!"<< endl;
			}
			else
				cout << "ɾ��ʧ��" << endl;
		}
		else if (choice == "8") {
			DispList(L);
		}
		else if (choice == "9") {
			DestroyList(L);
			cout << "���ٵ�����ɹ�" << endl;
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