#include "SLinkNode.cpp"
//#include "SLinkNode.cpp"
//#include "CSLinkNode.cpp"
//#include "DLinkNode.cpp"
int main() {
	system("title SLinkNode");
	int i; 
	ElemType e;
	LinkNode* L;
	InitList(L);
	InsElem(L, 1, 1);
	InsElem(L, 3, 2);
	InsElem(L, 1, 3);
	InsElem(L, 5, 4);
	InsElem(L, 4, 5);
	InsElem(L, 2, 6);
	cout << "���Ա�";
	DispList(L);
	cout << "���ȣ�" << GetLength(L) << endl;
	i = 3;
	GetElem(L, i, e);
	cout << "��" << i << "��Ԫ�أ�" << e << endl;
	e = 1;
	cout << "Ԫ��" << e << "�ǵ�" << Locate(L, e) << "��Ԫ��" << endl;
	i = 4;
	cout << "ɾ����" << i << "��Ԫ��" << endl;
	DelElem(L, i);
	cout << "���Ա�";
	DispList(L);
	DestroyList(L);
}