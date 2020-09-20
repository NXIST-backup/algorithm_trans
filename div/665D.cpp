#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <string.h>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>
//!dfs+greedy贪心
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9+7;
typedef pair<int,int> pii;

const int N = 2e5 + 50;

int t;
int n, m;
int h[N], e[N], ne[N], idx;
ll sz[N];
vector<ll> a;
bool st[N];
bool cmp(int a,int b)
{
    return a > b;
}
void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u)
{
    st[u] = true;
    sz[u] = 1;
    for (int i = h[u]; i != -1;i=ne[i]){
        int v = e[i];
        if(!st[v]){
            dfs(v);
            sz[u] += sz[v];
            a.push_back(sz[v] * (n - sz[v]));
        }
    }
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        memset(h, -1, sizeof h);
        memset(e, -1, sizeof e);
        memset(ne, -1, sizeof ne);
        memset(st, 0, sizeof st);
        memset(sz, 0, sizeof sz);
        vector<ll> prime;
        a.clear();
        idx = 0;
        
        for (int i = 0; i < n-1;i++){
            int u, v;
            cin >> u >> v;

            add(u, v);
            add(v, u);
        }

        dfs(1);


        sort(a.begin(), a.end());

        cin >> m;
        for (int i = 0; i < m;i++){
            int x;
            cin >> x;
            prime.push_back(x);
        }
        ll sum = 0;
        if(m>n-1){
            sort(prime.begin(), prime.end());
            while (prime.size()>n-1) {
                int temp = (prime[prime.size()-1]%INF * prime[prime.size()-2]) % INF;
                prime.pop_back();
                prime.pop_back();
                prime.push_back(temp);
            }

            for (int i = 0; i < n - 1;i++){
                sum = (sum+prime[i]%INF * a[i]) % INF;
            }

            cout << sum << endl;
        }
        else{
            while(prime.size()<n-1){
                prime.push_back(1);
            }
            sort(prime.begin(), prime.end());
            for (int i = 0; i < n - 1;i++){
                sum = (sum+prime[i]%INF * a[i]%INF) % INF;
            }

            cout << sum << endl;
        }
    }
}

