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

//二分图：当且仅当图中不含奇数环
//二分图就是把点集分为两份，点集内没有边，边只存在于两点集之间

#include "algorithm"
#include "cstring"
#include "iostream"


using namespace std;

const int N = 1e5 + 50, M = 2e5 + 50;

int n, m;

int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];

        if (!color[j]) {
            if (!dfs(j, 3 - c))
                return false;
        } else if (color[j] == c)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b;
        cin >> a >> b;

        add(a, b);
        add(b, a);
    }
    bool flag = true;

    for (int i = 1; i <= n; i++)
        if (!color[i]) {
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}