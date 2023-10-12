#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 100
//定义串
typedef struct {
    char data[MaxSize];
    int length;
}SqString;

//串赋值
void Assign(SqString& s, char* str) {
    int i;
    while (str[i] != '\0') {
        s.data[i] = str[i];
        i++;
    }
    s.length = i;
}
//销毁
void DestroyStr(SqString s) {

}
//串复制
void StrCopy(SqString& s, SqString t) {
    int i;
    for (i = 0; i < t.length; i++)
        s.data[i] = t.data[i];
    s.length = t.length;
}
//求串长
int StrLength(SqString s) {
    return s.length;
}
//判断相等
int StrEqual(SqString s, SqString t) {
    int i;
    if (s.length != t.length)
        return 0;
    else {
        for (i = 0; i < s.length; i++)
            if (s.data[i] != t.data[i])
                return 0;
        return 1;
    }
}
//串连接
SqString Concat(SqString s, SqString t) {
    SqString r;
    r.length = 0;
    int i, j;
    for (i = 0; i < s.length; i++)
        r.data[r.length++] = s.data[i];
    for (j = 0; j < t.length; j++)
        r.data[r.length++] = t.data[j];
    return r;
}
//求子串
SqString SubString(SqString s, int i, int j) {
    SqString t;
    int k;
    if (i<1 || i>s.length || j<1 || i + j>s.length)
        t.length = 0;
    else {
        for (k = i - 1; k < i + j - 1; k++)
            t.data[k - i + 1] = s.data;
        t.length = j;
    }
    return t;
}
//查找子串位置
int Index(SqString s, SqString t) {
    int i = 0, j = 0;
    while (i < s.length && j < t.length) {
        if (s.data[i] == t.data[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= t.length)
        return i - t.length;
    else
        return 0;
}
//子串插入
int InnStr(SqString& s, int i, SqString t) {
    int j;
    if (i<1 || i>s.length + 1)
        return 0;
    else {
        for (j = s.length - 1; j > i - 1; j--)
            s.data[j + t.length] = s.data[i];
        for (j = 0; j < t.length; j++)
            s.data[i + j - 1] = t.data[j];
        s.length = s.length + t.length;
        return 1;
    }
}
//子串删除
int DelStr(SqString& s, int i, int j) {
    int k;
    if (i<1 || i>s.length || j<1 || i + j>s.length)
        return 0;
    else {
        for (k = i + j - 1; k < s.length; k++)
            s.data[k - j] = s.data[k];
        s.length = s.length - j;
        return 1;
    }
}
//子串替换
SqString RspStr(SqString s, int i, int j, SqString t) {
    int k;
    SqString str;
    str.length = 0;
    if (i<0 || i>s.length || i + j - 1 > s.length)
        return str;
    for (k = 0; k < i - 1; k++)
        str.data[k] = s.data[k];
    for (k = 0; k < t.length; k++)
        str.data[i + k - 1] = t.data[k];
    for (k = i + j - 1; k < s.length; k++)
        str.data[t.length + k - j] = s.data[k];
    str.length = s.length + t.length - j;
    return str;
}
//输出串
void DispStr(SqString s) {
    int i;
    for (i = 0; i < s.length; i++)
        cout << s.data[i];
    cout << endl;
}


int main() {

    return 0;
}