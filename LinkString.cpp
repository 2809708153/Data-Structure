#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//��������
typedef struct node {
    char data;
    struct node* next;
}LinkString;


//����ֵ
void Assign(LinkString*& s, char* str) {
    int i = 0;
    LinkString* p, * tc;
    s = (LinkString*)malloc(sizeof(LinkString));
    tc = s;
    while (str[i] != '\0') {
        p = (LinkString*)malloc(sizeof(LinkString));
        p->data = str[i];
        tc->next = p;
        tc = p;
        i++;
    }
    tc->next = NULL;
}
//����
void DestroyStr(LinkString*& s) {
    LinkString* pre = s, * p = pre->next;
    while (p) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}
//������
void StrCopy(LinkString*& s, LinkString *t) {
    LinkString* p = t->next, * q, * tc;
    s = (LinkString*)malloc(sizeof(LinkString));
    tc = s;
    while (p) {
        q = (LinkString*)malloc(sizeof(LinkString));
        q->data = p->data;
        tc->next = q;
        tc = q;
        p = p->next;
    }
    tc->next = NULL;
}
//�󴮳�
int StrLength(LinkString *s) {
    int n = 0;
    LinkString* p = s->next;
    while (p) {
        n++;
        p = p->next;
    }
    return n;
}
//�ж����
int StrEqual(LinkString *s, LinkString *t) {
    LinkString* p = s->next, * q = t->next;
    while (p && q) {
        if (p->data != q->data)
            return 0;
        p = p->next;
        q = q->next;
    }
    if (p != NULL || q != NULL)
        return 0;
    else
        return 1;
}
//������
LinkString* Concat(LinkString* s, LinkString* t) {
    LinkString* p = s->next, * q, * tc, * r;
    r = (LinkString*)malloc(sizeof(LinkString));
    tc = r;
    while (p) {
        q = (LinkString*)malloc(sizeof(LinkString));
        q->data = p->data;
        tc->next = q;
        tc = q;
        p = p->next;
    }
    p = t->next;
    while (p) {
        q = (LinkString*)malloc(sizeof(LinkString));
        q->data = p->data;
        tc->next = q;
        tc = q;
        p = p->next;
    }
    t->next = NULL;
    return r;
}
//���Ӵ�
LinkString* SubString(LinkString* s, int i, int j) {
    int k = 1;
    LinkString* r, * p = s->next, * q, * tc;
    r = (LinkString*)malloc(sizeof(LinkString));
    r->next = NULL;
    if (i < 1)
        return r;
    tc = r;
    while (k < i && p) {
        p = p->next;
        k++;
    }
    if (p==NULL)
        return r;
    k = 1;
    q = p;
    while (k < j && q) {
        q = q->next;
        k++;
    }
    if (q == NULL)
        return r;
    k = 1;
    while (k <= j && p) {
        q = (LinkString*)malloc(sizeof(LinkString));
        q->data = p->data;
        tc->next = q;
        tc = q;
        p = p->next;
        k++;
    }
    tc->next = NULL;
    return r;
}
//�����Ӵ�λ��
int Index(LinkString *s, LinkString *t) {
    LinkString* p = s->next, * p1, * q, * q1;
    int i = 1;
    while (p) {
        q = t->next;
        if (p->data == q->data) {
            p1 = p->next; 
            q1 = q->next;
            while (p1 && q1 && p1->data == q1->data) {
                p1 = p->next;
                q1 = q->next;
            }
            if (q1 == NULL)
                return i;
        }
        p = p->next;
        i++;
    }
    return 0;
}
//�Ӵ�����
int InnStr(LinkString*& s, int i, LinkString *t) {
    LinkString* p = s, * q, * r;
    int k = 1;
    if (i < 1)
        return 0;
    while (k < i && p) {
        k++;
        p = p->next;
    } 
    if (p == NULL)
        return 0;
    q = t->next;
    while (q) {
        r = (LinkString*)malloc(sizeof(LinkString));
        r->data = q->data;
        r->next = p->next;
        p->next = r;
        p = p->next;
        q = q->next;
    }
}
//�Ӵ�ɾ��
int DelStr(LinkString*& s, int i, int j) {
    LinkString* p = s, * q;
    int k = 1;
    if (i < 1 || j < 1)
        return 0;
    while (k < i && p) {
        p = p->next;
        k++;
    }
    if (p == NULL)
        return 0;
    k = 1;
    q = p->next;
    while (k < i && q) {
        q = q->next;
        k++;
    }
    if (q == NULL)
        return 0;
    k = 1;
    while (k <= j) {
        q = p->next;
        if (q->next == NULL) {
            free(q);
            p->next = NULL;
        }
        else {
            p->next = q->next;
            free(q);
        }
        k++;
    }
    return 1;
}
//�Ӵ��滻
LinkString *RspStr(LinkString *s, int i, int j, LinkString *t) {
    int k;
    LinkString* str, * p = s->next, * p1 = t->next, * q, * r;
    str = (LinkString*)malloc(sizeof(LinkString));
    str->next = NULL;
    r = str;
    if (i <= 0 || i > StrLength(s) || j<0 || i + j - 1>StrLength(s))
        return str;
    for (k = 0; k < i - 1; k++) {
        q = (LinkString*)malloc(sizeof(LinkString));
        q->data = p->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p = p->next;
    }
    for (k = 0; k < j; k++)
        p = p->next;
    while (p1) {
        q = (LinkString*)malloc(sizeof(LinkString));
        q->data = p1->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    while (p) {
        q = (LinkString*)malloc(sizeof(LinkString));
        q->data = p->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
    return str;
}
//�����
void DispStr(LinkString *s) {
    LinkString* p = s->next;
    while (p) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}


int main() {

    return 0;
}