#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

int n, m;
const int N = 30050;
int h[N], e[N], ne[N], idx;
int d[N];
bitset<N> f[N];
vector<int> ans;
void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n;i++){
        if(d[i]==0)
            q.push(i);
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (int i = h[t]; ~i;i=ne[i]){
            int v = e[i];
            if(--d[v]==0)
                q.push(v);
        }
    }

}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 0; i < m;i++){
        int x, y;
        cin >> x >> y;
        d[y]++;
        add(x, y);
    }

    topsort();

    for (int i = ans.size() - 1; i >= 0;i--){
        int v = ans[i];
        f[v][v] = 1;
        for (int j = h[v]; ~j;j=ne[j]){
            f[v] |= f[e[j]];
        }
    }

    for (int i = 1; i <= n;i++)
        cout << f[i].count() << endl;
}