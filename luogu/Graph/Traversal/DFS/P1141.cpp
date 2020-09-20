#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

const int N = 1050;
int n, m;
char a[N][N];
bool ch[N][N];
int st[N][N],d[N][N];
queue<pair<int, int>> q;
int cnt = 0;
void dfs(int x,int y)
{
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    q.push({x, y});

    for (int i = 0; i < 4;i++)
    {
        int x1 = x + dx[i], y1 = y + dy[i];
        if(!d[x1][y1]&&x1>=0&&y1>=0&&x1<n&&y1<n&&ch[x1][y1]==(!ch[x][y]))
        {
            d[x1][y1] = 1;
            dfs(x1, y1);
            cnt++;
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n;j++)
            ch[i][j] = a[i][j] - '0';
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        if(st[x-1][y-1])
            cout << st[x-1][y-1] << endl;
        else
        {
            cnt = 0;
            dfs(x-1, y-1);
            if(q.size()==1)
            {
                auto t = q.front();
                st[t.first][t.second] = cnt + 1;
                q.pop();
            }
            else {
                while (q.size()) {
                    auto t = q.front();
                    st[t.first][t.second] = cnt;
                    q.pop();
                }
            }
            cout << st[x-1][y-1] << endl;
        }
    }
}
