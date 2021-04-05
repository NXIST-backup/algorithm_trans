/*
  Problem Name:最优贸易
  algorithm tag:DP
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
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed
//三种做法
//spfa分层图
//dfs 记忆化搜索
//spfa

const int N = 1e5 + 5,M = 1e6 + 5;
int h[N*3],e[M*3],ne[M*3],w[M*3],idx;
int val[N];
int dist[N*3];
int st[N*3];
int q[N*3];
int n,m;
void add(int a,int b,int c)
{
  e[idx]=b;
  ne[idx]=h[a];
  w[idx]=c;
  h[a]=idx++;
}
void addEdge(int a,int b)
{
  add(a,b,0);
  add(a+n,b+n,0);
  add(a+2*n,b+2*n,0);
  add(a,a+n,-val[a]);
  add(a,a+2*n,val[a]);
}
void spfa()
{
  int hh=0,tt=0;
  memset(dist,-0x3f,sizeof dist);
  dist[1]=0;
  st[1]=1;
  q[0]=1;
  while(hh>=tt){
    int t = q[++hh];

    st[t]=0;

    for(int i=h[t];~i;i=ne[i]){
      int j = e[i];

      if(dist[j]<dist[t]+w[i]){
        dist[j]=dist[t]+w[i];
        st[j]=1;
        q[++tt]=j;
      }
    }
  }
}
int main()
{
  iosf;
  memset(h,-1,sizeof h);
  cin >> n >> m;

  for(int i = 1;i <= n;i++)
    cin>>w[i];

  for(int i=1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    addEdge(a,b);
    if(c==2)
      addEdge(b,a);
  }

  spfa();

  cout<<dist[3*n]<<endl;
}