//并查集加前缀和
//前缀并查集 合并 后缀并查集



#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int n, m, k;
int s;

struct DSU
{
    int p[505];

    void init()
    {
        for (int i = 1; i <= n;i++)
            p[i] = i;
    }
    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    int count()
    {
        int count = 0;
        for (int i = 1; i <= n;i++)
        if(p[i]==i)
            count++;
        return count;
    }

    void link(int a,int b)
    {
        p[find(a)] = find(b);
    }
} L[10050], R[10050];

DSU hebing(DSU L,DSU R)
{
    DSU a = L;
    for (int i = 1; i <= n;i++)
        a.link(i, R.find(i));
    return a;
}
int l[10050], r[10050];
int main()
{
    cin >> n >> m;
    L[0].init();
    for (int i = 1; i <= m;i++)
    {
        cin >> l[i];
        cin >> r[i];
        L[i] = L[i - 1];
        L[i].link(l[i], r[i]);
    }
    R[m + 1].init();
    for (int i = m; i >= 1;i--)
    {
        R[i] = R[i + 1];
        R[i].link(l[i], r[i]);
    }

    cin >> k;
    while(k--){

        int x1, y1;
        cin >> x1 >> y1;

        DSU h = hebing(L[x1 - 1], R[y1 + 1]);

        cout << h.count() << endl;
    }
}