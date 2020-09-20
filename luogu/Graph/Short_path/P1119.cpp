//floyd算法本质是通过中间点来更新两点之间的最短距离
//而这题正好是把模板中的中间点k换成时间。
//时间复杂度从O(n^3*q)->O(n^3+q)


#include "iostream"
#include "algorithm"
#include "cstring"
#include "queue"

using namespace std;

const int N = 210, inf = 1e9;

int n, m, q;
int t[N],u[N];
int d[N][N];

void floyd(int k)
{
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
        {
            d[j][i] = d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
}





int main()
{
    cin >> n >> m;

    for (int i = 0; i < n;i++) 
    {
        cin >> t[i];
    }
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            {
                if(i==j)
                    d[i][j] = 0;
                else
                    d[i][j] = inf;
            }
    for (int i = 1; i <= m;i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = min(d[a][b], w);
        d[b][a] = min(d[b][a], w);
    }
    cin >> q;
    int now = 0;
    while (q--)
    {
        int a, b, time;
        cin >> a >> b >> time;

        while (t[now]<=time&&now<n) {

            floyd(now);
            now++;
        }
        if(t[a]>time||t[b]>time)
            cout << -1 << endl;
        else
        {
            if(d[a][b]==1e9)
                cout << -1 << endl;
            else
                cout << d[a][b] << endl;
        }
    }
}
