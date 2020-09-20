#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <utility>
#include <map>
using namespace std;
const int N = 55;

int n, m;
int ma[N][N];
int st[N][N];
int d[N][N];
map<char, pair<int, int>> judge;
int bfs(int x1,int y1,int x2,int y2,char opt[])
{
    queue<pair<int, int>> q;
    q.push({x1, y1});
    d[x1][y1]=1;
    while (q.size()) {
        auto t = q.front();
        q.pop();

        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int op[3] = {1, 2, 3};
        int cha = opt[0];
        for (int i = 0; i < 4;i++)
        {
            for (int j = 0; j < 3;j++)
            {
                
                int xx = t.first + dx[i] * op[j], yy = t.second + dy[i] * op[j];
                if(judge[])
                {

                }
                if(!d[xx][yy]&&xx>=0&&yy>=0&&xx<=n&&yy<=m&&!st[xx][yy])
                {
                    q.push({xx, yy});
                    d[xx][yy] +=d[t.first][t.second];
                }
                if(xx==x2&&yy==y2)
                {
                    return d[xx][yy];
                }
            }
        }
    }
    return -1;
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
        {
            cin >> ma[i][j];
            if(ma[i][j])
            {
                st[i][j] = 1;
                st[i - 1][j] = 1;
                st[i][j - 1] = 1;
                st[i - 1][j - 1] = 1;
            }
        }
    cout << endl;
    for (int i = 0; i <= n;i++)
    {
        for (int j = 0; j <= m;j++)
            cout << st[i][j] << " ";
        cout << endl;
    }

    judge['E'].first=1,judge['E'].second=0;
    judge['N'] = 'N';
    judge[{-1, 0}] = 'W';
    judge[{0, -1}] = 'S';

    int x1, x2, y1, y2;
    char op[2];
    cin >> x1 >> y1 >> x2 >> y2 >> op;
    cout << bfs(x1, y1, x2, y2, op) << endl;
    for (int i = 0; i <= n;i++)
    {
        for (int j = 0; j <= m;j++)
            cout << d[i][j] << "   ";
        cout << endl;
    }

}