//拓扑序列：
//1.有向图
//2.所有边都从前指向后的 eg. 1——>2——>3这就是拓扑序列
//notice：有向无环图肯定存在拓扑序列，有环一定不是拓扑序列

//A.入度 B.出度
//入度是指有多少可以到该点的不同路径        1——————>2   入度 出度
//出度是指有多少可以出去的不同路径          \       / 1_ 0    2
//                                        \_>3<_/  2_ 1    1
//                                                 3_ 2    0



#include "iostream"
#include "queue"
#include "algorithm"
#include "cstring"
#include <cstdio>
#include <queue>
using namespace std;

const int N = 1e5 + 50;

int n, m;

int h[N], e[N], ne[N], idx;
int st[N],q[N];

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;

    for (int i = 1; i <= n;i++)//1.把所有入度为0的点加入队列
        if(!st[i])
            q[++tt] = i;
    while (hh<=tt)//2.遍历一遍后如果队列总数量等于序列大小则是拓扑序列 
    {             // 因为如果带环的图是会超过序列大小而且超过的数量是序列大小数量加上环的数量
        int t = q[hh++];
        for (int i = h[t]; i != -1;i=ne[i])
        {
            int j = e[i];
            st[j]--;
            if(st[j]==0)
                q[++tt]=j;
        }
    }

    return tt == n - 1;
}


int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        st[b]++;//记录入度数
    }

    if(topsort())
    {
        for (int i = 0; i < n;i++)
            cout << q[i]<<" ";
        puts("");
    }
    else
        cout << -1 << endl;
}

