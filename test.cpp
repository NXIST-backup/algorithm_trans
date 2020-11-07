#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;


typedef struct Snode 
{
    int data; //数据域
    struct Snode *next; //指针域
}Snode,*LinkStack;

 

bool InitStack(LinkStack &S) //构造一个空栈S
{
    S=NULL;
    return true;
}

 

bool Push(LinkStack &S, int e) //在栈顶插入元素e
{
    LinkStack p;
    p = new Snode; //生成新结点
    p->data = e; //将e放在新结点数据域
    p->next = S; //将新结点的指针域指向S，即将S的地址赋值给新结点的指针域
    S = p; //修改栈顶指针为p
    return true;
}

 

bool Pop(LinkStack &S, int &e) //删除S的栈顶元素，用e保存其值

{
    LinkStack p;
    if (S==NULL) //栈空
        return false;
    e=S->data; //将栈顶元素赋给e
    p=S; //用p保存栈顶元素地址，以备释放
    S=S->next; //修改栈顶指针，指向下一个结点
    delete p; //释放原栈顶元素的空间
    return true;
}

 

int GetTop(LinkStack S) //返回S的栈顶元素，不修改栈顶指针
{
    if (S!=NULL) //栈非空
        return S->data; //返回栈顶元素的值，栈顶指针不变
    else
        return -1;
}

void Reverse(LinkStack &S)
{
    int stk[1000] = {0};
    int idx = 0;
    int val = 0;
    bool flag = 1;
    while(flag){
        stk[++idx] = GetTop(S);
        flag = Pop(S, val);
    }
    while(--idx){
        Push(S, stk[idx]);
    }
}
int main()
{
    LinkStack S;
    InitStack(S);

    int n;
    cin >> n;

    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        Push(S, x);
    }

    bool flag = 1;
    int tmp = 0;
    Reverse(S);
    while(flag){
        int st = GetTop(S);
        cout << st << " ";
        flag = Pop(S, tmp);
    }
    cout << endl;
}