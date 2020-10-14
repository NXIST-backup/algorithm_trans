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
int n, d, k;
vector<pii> a;
int st[N];
bool cmp(pii a,pii b)
{
    if(a.second<b.second)
        return true;
    else if(a.second==b.second){
        if(a.first<b.first)
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;

    cin >> n >> d >> k;

    for (int i = 0; i < n;i++){
        int ts, id;
        cin >> ts >> id;
        a.push_back({ts, id});
    }

    sort(a.begin(), a.end(), cmp);

    queue<int> q;
    int flag = a[0].second;
    for(auto item:a){
        if(flag!=item.second){
            while(q.size())
                q.pop();
            flag = item.second;
            q.push(item.first);
        }
        else
            q.push(item.first);
        if(q.size()==k){
            int t1 = q.front();
            int t2 = q.back();
            if(t2-t1 < d&&!st[item.second]){
                st[item.second] = 1;
                q.pop();
            }
            else
                q.pop();
        }
    }

    for (int i = 0; i <= N;i++)
        if(st[i])
            cout << i << endl;
}