//并查集
//1.将两个集合合并
//2.询问两个元素是否在一个集合

//基本原理：每个集合用一棵树来表示。树根的编号就是整个集合的编号。
//每个节点存储它的父节点，p[x]表示x的父节点。

//问题1：如何判断树根：if(p[x]==x)
//问题2：如何求x的集合编号：while(p[x]!=x) x=px[x]; 
//!!优化：寻找到父节点后所有节点直接连接父节点(路径压缩)
//问题3：如何合并两个集合：px是x的集合编号，py是y的集合编号。p[x]=y。

#include "iostream"
using namespace std;

const int N = 100050;

int n,m;
int p[N];

int find(int x)//返回x的祖宗节点+节点压缩
{
    if(p[x]!=x)
        p[x] = find(p[x]);//节点压缩加寻找  如果不寻找不需要加赋值
    return p[x];
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i < n;i++)
        p[i] = i;
    while(m--)
    {
        char op[2];
        int a, b;
        cin >> op >> a >> b;

        if(op[0]=='M')
            p[find(a)] = find(b);
        else
        {
            if(find(a)==find(b))
                puts("Yes");
                else
                    puts("No");
        }
    }
}


//并查集题目 P3367模板