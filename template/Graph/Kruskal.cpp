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
//     \匈牙利算法 O(mn),实际运行时间一般远小于O(mn)
//


//Kruskal
//1.将所有边按权重从小到大排序
//2.枚举每条边a,b,权重c
//  if a,b不连通,就把这条边加入集合(连一条边)中


#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"
#include <algorithm>
using namespace std;
const int N = 200010;

int n, m;
int p[N];

struct Edge
{
    int a, b, w;

    bool operator< (const Edge &W)const //重置小于号
    {
        return w < W.w;
    }

} edges[N];

int find(int x)
{
    if(p[x]!=x)
        p[x] = find(p[x]);
    return p[x];
}



int main()
{
    cin >> n >> m;

    for (int i = 0; i < m;i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    sort(edges, edges + m);

    for (int i = 1; i <= n;i++)
        p[i] = i;

    int res = 0, cnt = 0;//res是最小生成树所有树边的权重之和,cnt使我们当前存了多少条边

    for (int i = 0; i <= m;i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if(a!=b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }

    }
    if(cnt<n-1)
        cout << "impossible" << endl;
    else
        cout << res << endl;
}