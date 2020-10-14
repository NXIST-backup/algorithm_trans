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

int t;
int r,c;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char g[250][250];
int st[250][250];
int bfs(int x1,int y1,int x2,int y2)
{
    queue<pii> q;
    q.push({x1, y1});
    st[x1][y1] = 1;
    while(q.size()){
        auto t = q.front();
        if(t.first==x2&&t.second==y2)
            break;
        q.pop();

        for (int i = 0; i < 4;i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x>=1&&x<=r&&y>=1&&y<=c&&g[x][y]!='#'&&!st[x][y]){
                q.push({x, y});
                st[x][y] += st[t.first][t.second]+1;
            }
        }
    }
}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;

    cin >> t;

    while(t--){
        cin >> r >> c;
        int x1, y1, x2, y2;
        for (int i = 1; i <= r;i++){
            for (int j = 1; j <= c;j++){
                char c;
                cin >> c;
                if(c=='S')
                    x1 = i, y1 = j;
                if(c=='E')
                    x2 = i, y2 = j;
                g[i][j] = c;
            }
        }
        bfs(x1, y1, x2, y2);
        if(st[x2][y2])
            cout << st[x2][y2]-1 << endl;
        else
            cout << "oop!" << endl;

        memset(st, 0, sizeof st);
    }
}