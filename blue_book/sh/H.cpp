#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#define mp make_pair
using namespace std;
const int N = 510;
typedef pair<int, int> PII;

int n, m, t, x1, y1, x2, y2, ti;
char a[N][N];
int main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    cin >> ti;
    while (ti--) {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        if (t == 1) {
            if (y1 != y2)
                puts("N");
            else {
                bool flag = true;
                for (int i = x1; i <= x2; i++)
                    if (a[i][y1] == '1')
                        flag = false;
                if (flag && x1 <= x2)
                    puts("Y");
                else
                    puts("N");
            }
        } else if (t == 2) {
            if (x1 != x2)
                puts("N");
            else {
                bool flag = true;
                for (int i = y1; i <= y2; i++)
                    if (a[x1][i] == '1')
                        flag = false;
                if (flag && y1 <= y2)
                    puts("Y");
                else
                    puts("N");
            }
        } else {
            queue<PII> que;
            int dx[] = {1, 0}, dy[] = {0, 1};
            que.push(mp(x1, y1));
            bool ffm[N][N], flag = false;
            memset(ffm, false, sizeof(ffm));
            while (!que.empty()) {
                PII t = que.front();
                que.pop();
                int tx = t.first, ty = t.second;
                for (int i = 0; i < 2; i++) {
                    int px = tx + dx[i], py = ty + dy[i];
                    if (ffm[px][py] == true)
                        continue;
                    if (a[px][py] == '1')
                        continue;
                    if (px < x1 || px > x2 || py < y1 || py > y2)
                        continue;
                    if (px == x2 && py == y2) {
                        flag = true;
                        break;
                    }
                    que.push(mp(px, py));
                }
                if (flag == true)
                    break;
            }
            if (flag)
                puts("Y");
            else
                puts("N");
        }
    }
}