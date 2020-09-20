#include <cstring>
#include <iostream>

using namespace std;
const int N = 1005;
const int M = 1005;
int a[N][M];
int s[N][M];
int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j];
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        printf("%d\n", s[x2][y2] - s[x1 - 1][y1 - 1]);
    }
}