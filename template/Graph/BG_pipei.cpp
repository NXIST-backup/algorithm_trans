//
//。                        
//.                       /朴素版Prim O(n^2) 稠密图一般用这个
//.         普利姆算法(Prim)
//         /.             \堆优化版Prim O(mlogn) 
//最小生成树
//         \                              
//.         克鲁斯卡尔算法(Kruskal) O(mlogm) 稀疏图用这个
//
//
//
//
//.    /染色法  O(n+m)
//二分图
//     \匈牙利算法 O(mn),实际运行时间一般远小于O(mn) 最大匹配问题
//


#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

const int N = 550,M=1e5+50;

int n1, n2, m;

int h[N], e[M], ne[M], idx;
int match[N];//右边点集现匹配的点(这里指女生)
bool st[N];//判重


void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


bool find(int x)
{
    for (int i = h[x]; i != -1;i=ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j]==0||find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    cin >> n1 >> n2 >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b;

        cin >> a >> b;
        add(a, b);
    }

    int res = 0;

    for (int i = 1; i <= n1;i++)
    {
        memset(st, false, sizeof st);
        if(find(i))
            res++;
    }

    cout << res << endl;
}
