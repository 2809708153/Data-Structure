#include <iostream>
#include <bits/stdc++.h>
using namespace std;


typedef int Status;
typedef int ElemType;    //元素类型 
#define LIST_INIT_SIZE 100 
#define LISTINCREMENT 10 
typedef struct {
	ElemType* elem; 
	int length;
	int listsize; 
}SqList;    //结点类型 
//2、 相关函数操作的伪码如下：
Status InitList(SqList* L) {
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);    //存储分配失败 
	L->length = 0; 	//空表长度为零 
	L->listsize = LIST_INIT_SIZE;      //初始存储容量 
	return OK;
}
Status DestroyList(SqList* L) {
	if (L->elem)
		free(L->elem); 	//释放线性表占用的存储空间 
	L->elem = NULL; 	//置空 
	L->length = 0;
	L->listsize = 0;
	return OK;
}
Status ClearList(SqList* L) {
	L->length = 0;
	return OK;
}
Status ListEmpty(SqList L) {
	if (L.length == 0) return TRUE; //若长度为零，返回TRUE 
	else return FALSE;


}
int ListLength(SqList L) {
	return L.length;
}
Status GetElem(SqList L, int i, ElemType* e) {
	if (i<1 || i>L.length) return FALSE; 	//若超出范围，返回FALSE 
	*e = L.elem[i - 1]; 	//用e带回第i个数据 
	return OK;
}
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType) {
	i = 1;
	p = L.elem;  //p的初值为存储空间基址 
	while (i <= L.length && !(*compare)(*p++, e)) ++i;
	if (i < L.length) return i;  //若有满足条件的元素，返回相应位置 
	else return 0;
}
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e) {
	for (i = 2; i <= L.length; i++) {
		if (L.elem[i - 1] == cur_e) {
			*pre_e = L.elem[i - 2];
			return OK;
		}
		else continue;
	}//从第二个元素开始找，若有与cur_e相等的数据元素，将其前驱的值赋给pre_e并返回   return FALSE; 
}
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e) {
	for (i = 1; i < L.length; i++) {
		if (L.elem[i - 1] == cur_e) {
			*pre_e = L.elem[i];
			return OK;
		}//从第一个元素开始找，一直到倒数第二个元素，若有与cur_e相等的数据元素，将其后继的值赋给pre_e并返回 
		else continue;
	}
	return FALSE;
}
Status ListInsert(SqList* L, int i, ElemType e) {


	if (i<1 || i>(*L).length + 1) return ERROR;  //i值不合法的情况 
	if ((*L).length > (*L).listsize) {
		ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType)); //增加分配 
		if (!newbase) exit(OVERFLOW); 	//分配失败 
		L->elem = newbase; 	//新的基址 
		L->listsize += LISTINCREMENT;
	}
	q = &(L->elem[i - 1]); 	//q为插入的位置 
	for (p = &(L->elem[L->length - 1]); p >= q; --p) *(p + 1) = *p; //插入位置之后的元素一一后移 
	*q = e; 	//插入e 
	L->length++; 	//表长加一 
	return OK;
}
Status ListDelete(SqList* L, int i, ElemType* e) {
	if ((i < 1) || (i > L->length)) return ERROR; 	//i值不合法 
	p = &(L->elem[i - 1]); 	//p为被删元素位置 
	*e = *p; 	//将被删元素的值赋给e 
	q = L->elem + L->length - 1; 	//末尾元素位置 
	for (++p; p <= q; ++p) *(p - 1) = *(p); 	//被删元素之后的元素左移 
	L->length--; 	//表长减一 
	return OK;
}
Status ListTraverse(SqList L, void(*visit)(ElemType*)) {
	for (i = 1; i <= L.length; i++)

		visit(&L.elem[i - 1]);
	return OK;
}


//依次对每个数据元素调用函数visit() 

3、 主函数的伪码算法：
int main() {
	printf("本程序对整型数据进行操作\n");
	printf("创建新的顺序表L\n");
	if (InitList(&L)) printf("创建成功\n");
	else printf("创建失败\n");
	printf("\n");
	printf("输入元素个数n\n");
	scanf("%d", &n);
	printf("\n");
	printf("输入%d个数据元素\n", n);
	for (i = 1; i <= n; i++) {
		scanf(temp);


		ListInsert(&L, i, temp);
	}
	printf("\n");
	printf("根据下列序号(输入相应序号)完成各操作：\n");
	printf("1:将线性表重置为空表\n");
	printf("2:判断线性表是否为空\n");
	printf("3:求线性表的长度\n");
	printf("4:求线性表中第i个元素的值\n");
	printf("5:求线性表中值为e的函数的位置\n");
	printf("6:求元素cur_e的前驱元素的值\n");
	printf("7:求元素cur_e的后继元素的值\n");
	printf("8:在L的第i个位置之前插入新的数据元素e\n");
	printf("9:删除L的第i个数据元素，并用e返回其值\n");
	printf("10:遍历线性表，输出各元素的值\n");
	printf("0:结束操作\n\n");
	do {
		scanf("%d", &num);
		switch (num) {
		case 1:ClearList(&L); break;
		case 2:
			if (ListEmpty(L)) printf("该线性表为空\n");
			else printf("该线性表非空\n");
			break;
		case 3:
			printf("线性表的长度为%d\n", ListLength(L));
			break;
		case 4:
			printf("输入位置i\n");
			scanf("%d", &i);
			if (GetElem(L, i, &e) == 0) printf("i值不合法\n");
			else printf("第%d位上的数据元素为%d\n", i, e); break;
		case 5:
			printf("输入e的值\n");
			scanf("%d", &e);
			if (LocateElem(L, e, compare)) printf("值为%d的元素在第%d位\n", e, LocateElem(L, e, compare));
			else printf("值为%d的数据不存在\n", e); break;
		case 6:
			printf("输入cur_e的值\n");
			scanf(cur_e);
			if (PriorElem(L, cur_e, &pre_e)) printf("%d的前驱元素为%d\n", cur_e, pre_e); else printf("不存在%d的前驱元素\n", cur_e); break;
		case 7:


			printf("输入cur_e的值\n");
			scanf(cur_e);
			if (NextElem(L, cur_e, &next_e)) printf("%d的后继元素为%d\n", cur_e, next_e); else printf("不存在%d的后继元素\n", cur_e); break;
		case 8:
			printf("分别输入插入元素e与插入位置i的值\n");
			scanf(e, i);
			if (ListInsert(&L, i, e)) printf("插入成功\n");
			else printf("插入失败\n");
			break;
		case 9:
			printf("输入删除位置i的值\n");
			scanf(i);
			if (ListDelete(&L, i, &e)) printf("已删除第%d位的元素%d\n", i, e);
			else printf("i值不合法\n"); break;
		case 10:
			printf("当前线性表为:\n");
			ListTraverse(L, visit); break;
		case 0:
			DestroyList(&L);
			break;
		}
		printf("\n");
	} while (num != 0);
	return 0;
}
（二）  带头结点的单链表的表示和实现
1、 元素类型，结点类型和指针类型：
typedef int Status;
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
2、 相关函数的伪码算法：
void CreatList_L(LinkList * L, int n) {
	*L = (LinkList)malloc(sizeof(LNode));

	(*L)->next = NULL;
	q = L;
	for (i = n; i > 0; i--) {


		//先建立一个带头结点的单链表 

		p = (LinkList)malloc(sizeof(LNode)); //生成新结点 
		scanf("%d", &(p->data)); 	//输入元素值 
		p->next = (*L)->next;


		q->next = p; 	//插入到链尾 
		q = p;
	}
	p->next = NULL;
	return OK;
}//顺位序输入n个元素的值，建立带头结点的单链线性表 
Status InitList(LinkList* L) {
	*L = (LinkList)malloc(sizeof(LNode)); 	//产生头结点 
	if (!*L) exit(OVERFLOW); 	//创建失败 
	(*ls)->next = NULL;
	return OK;
}
Status DestroyList(LinkList L) {
	p = L;  //p的初始位置为头结点位置 
	while (p) {
		q = p->next;
		free(p); 	//释放结点 
		p = q;
	}
	return OK;
}
Status ClearList(LinkList L) {
	p = L->next;
	while (p) {
		q = p->next;
		free(p); 	//释放结点 
		p = q;
	}
	L->next = NULL; 	//置为空表 
	return OK;
}
Status ListEmpty(LinkList L) {

	if (L->next) return FALSE;
	else return TRUE;
}
int ListLength(LinkList L) {


	//若链表不为空，返回FALSE 
	//若链表为空，返回TRUE 

	i = 0; p = ls->next; 	//用i记录长度，且i的初值为零 
	while (p) {
		i++;


		p = p->next;
	}
	return i;
}
Status GetElem_L(LinkList L, int i, ElemType* e) {
	p = L->next; j = 1; 	//p指向第一个结点,j进行计数 
	while (p && j < i) { 	//顺着指针向后查找，直到指向第i个元素或p为空 
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR; 	//第i个元素不存在 
	*e = p->data; 	//取第i个元素 
	return OK;
}
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	p = L->next; i = 1; 	//i表示当前元素位置 
	while (p) {
		if (compare(e, p->data)) return i; 	//若满足compare函数，返回对应位置i 
		else { 	//否则指向下一个结点 
			p = p->next;
			i++;
		}
	}
	return 0;
}
Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e) {
	q = L->next; 	//用q来存储前一个结点 
	p = q->next;
	while (p) {
		if (p->data == cur_e) {
			*pre_e = q->data;
			return OK;
		}
		P->next; q = q->next;
	}//从第二个元素开始找，若有与cur_e相等的数据元素，将其前驱的值赋给pre_e并返回   return FALSE; 
}
Status NextElem(LinkList L, ElemType cur_e, ElemType* next_e) {
	q = L->next;
	p = q->next; 	//p表示后继元素结点位置 


	while (p) {
		if (q->data == cur_e) {
			*pre_e = p->data;
			return OK;
		}
		P = p->next; q = q->next;
	}
	return FALSE;
}
Status ListInsert_L(LinkList* L, int i, ElemType e) {
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next; ++j;
	}
	if (!p || j > i - 1) return ERROR;
	LinkList s = (LinkList)malloc(sizeof(LNode)); 	//生成新结点 
	s->data = e; s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList* L, int i, ElemType* e) {
	p = L;
	j = 0;
	while (p->next && j < i - 1) { 	//寻找第i个结点，p为其前趋 
		p = p->next; ++j;
	}

	if (!(p->next) || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;


	//删除的位置不合理的情况 

	free(q); 	//删除释放结点 
	return OK;
}
Status ListTraverse(LinkList L, void(*visit)(ElemType*)) {
	p = L->next;
	while (p) {

		visit(&p->data);
		p = p->next;
	}
	return OK;


	//对各数据依次执行visit函数 


}