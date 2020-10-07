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

const int N = 1e5 + 50;
int n, m, t;
bool st[N];
int last[N];
int sum[N];
vector<pii> list;

bool cmp(pii a,pii b)
{
    if(a.first<b.first)
        return true;
    else
        return false;
}
int main()
{
    cin >> n >> m >> t;

    for (int i = 0; i < m;i++){
        int ts, id;
        cin >> ts >> id;
        list.push_back({ts, id});
    }

    sort(list.begin(), list.end(), cmp);

    ll ans = 0;
    for(auto item:list){
        int id, ts;
        ts = item.first;
        id = item.second;
        if(last[id]!=ts){
            sum[id] = max(sum[id] - (ts - last[id] - 1), 0);
            if(sum[id]<=3&&st[id])
                st[id] = 0;

        }
        last[id] = ts;
        sum[id] += 2;
        if(sum[id]>5&&!st[id])
            st[id] = 1;
    }
    for (int i = 1; i <= n;i++){
        sum[i] = max(sum[i] - (t - last[i]), 0);
        if(sum[i]<=3&&st[i])
            st[i] = 0;
    }
    for (int i = 1; i <= n;i++) {
        ans += st[i];
    }
    cout << ans << endl;
}