#include "iostream"
#include "queue"
#include "algorithm"
#include "map"
#include "cstring"
#include <queue>
#include <utility>

using namespace std;

int n, m;
const int N = 450;
int st[N][N];
int che[N][N];


void bfs(int x,int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

    while (q.size()) 
    {
        auto t = q.front();
        q.pop();
        st[x][y] = 1;
        for (int i = 0; i < 8;i++)
        {
            int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2}, dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};
            int x1 = t.first + dx[i], y1 = t.second + dy[i];
            if(!st[x1][y1]&&x1>=1&&y1>=1&&x1<=n&&y1<=m)
            {
                q.push({x1, y1});
                st[x1][y1] = st[t.first][t.second]+1;
            }
        }
    }

}



int main()
{
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    memset(st, 0, sizeof st);

    bfs(x, y);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            printf("%-5d", st[i][j]-1);
        }
        cout << endl;
    }
}