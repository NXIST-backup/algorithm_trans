/*
  Problem Name:武士风度的牛
  algorithm tag:Flood fill,BFS
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

char g[155][155];
int n,m;
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
int dz[8]={1,-1,1,-1,};

int main()
{
    iosf;

    cin >> n >> m;
    int x1,y1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            g[i][j]=c;
            if(c=='K')
                x1=i,y1=j;
        }
    }

}

