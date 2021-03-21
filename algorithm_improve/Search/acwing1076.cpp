/*
  Problem Name:迷宫问题
  algorithm tag:Flood fill
*/

#include <algorithm>
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 1050;
int n;
bool g[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
map<pii,pii> rem;

int main()
{
    iosf;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool x;
            cin >> x;
            g[i][j] = !x;
        }
    }

    queue<pii> q;
    vector<pii> ans;
    q.push({1,1});
    while(q.size()){
        auto t = q.front();
        q.pop();
        if(t.first==n&&t.second==n)
            break;
        for(int i=0;i<4;i++){
            int x=t.first+dx[i];
            int y=t.second+dy[i];

            if(g[x][y]){
                q.push({x,y});
                g[x][y]=0;
                rem[{x,y}]={t.first,t.second};
            }
        }
    }
    int x=rem[{n,n}].first;
    int y=rem[{n,n}].second;
    ans.push_back({n,n});
    while(x!=1||y!=1){
        ans.push_back({x,y});
        int x1=x,y1=y;
        x=rem[{x1,y1}].first;
        y=rem[{x1,y1}].second;
    }
    ans.push_back({1,1});

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i].first-1<<" "<<ans[i].second-1<<endl;
    }
}   