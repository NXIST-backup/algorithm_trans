#include "iostream"
using namespace std;

const int N = 50;

int n;
int g[N][N];
bool col[N], dg[N], udg[N];//对角线
int h = 3;
int count = 0;
void dfs(int u)
{
    if(u==n)//行
    {
        count++;
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
                if(g[i][j]&&h)
                    cout << j + 1 << " ";
        }
        if(h)
        puts("");
        if(h)
        h--;
        return;
    }
    for (int i = 0; i < n;i++)//列
    {
        if(!col[i]&&!dg[u+i]&&!udg[n-u+i])
        {
            g[u][i] = 1;
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = 0;
        }
    }
}


int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            g[i][j] = 0;
    dfs(0);
    printf("%d", count);
}

