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
	cout << "线性表：";
	DispList(L);
	cout << "长度：" << GetLength(L) << endl;
	i = 3;
	GetElem(L, i, e);
	cout << "第" << i << "个元素：" << e << endl;
	e = 1;
	cout << "元素" << e << "是第" << Locate(L, e) << "个元素" << endl;
	i = 4;
	cout << "删除第" << i << "个元素" << endl;
	DelElem(L, i);
	cout << "线性表：";
	DispList(L);
	DestroyList(L);
}