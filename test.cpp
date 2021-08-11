#include <stdio.h>
#include <string.h>

char g[105][105];

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int n, m;
int x1, x2, y1, y2;
int st[105][105];
int flag;
struct Q
{
    int x, y;
} q[20005];
int main()
{
    while (scanf("%d%d%d", &n, &m) != EOF) {
        flag = 0;
        memset(st, 0, sizeof st);
        for (int i = 0; i < m; i++)
            scanf("%s", g[i]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 's')
                    x1 = i, y1 = j;
                if (g[i][j] == 'e')
                    x2 = i, y2 = j;
            }
        }

        int ss = 0, tt = 0;
        q[tt].x = x1;
        q[tt].y = y1;
        st[x1][y1] = 1;

        while (ss <= tt) {
            int x = q[ss].x;
            int y = q[ss++].y;

            if (x == x2 && y == y2) {
                flag = 1;
                break;
            }

            for (int i = 0; i < 8; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (dx[i] == 2 && g[x + 1][y] == '#')
                    continue;
                if (dx[i] == -2 && g[x - 1][y] == '#')
                    continue;
                if (dy[i] == 2 && g[x][y + 1] == '#')
                    continue;
                if (dy[i] == -2 && g[x][y - 1] == '#')
                    continue;
                if (a < 0 || a >= m || b < 0 || b >= n || g[a][b] == '#' || st[a][b])
                    continue;
                st[a][b] = st[x][y] + 1;
                q[++tt].x = a;
                q[tt].y = b;
            }
        }
        if (flag)
            printf("%d\n", st[x2][y2] - 1);
        else
            printf("-1\n");
    }
}
