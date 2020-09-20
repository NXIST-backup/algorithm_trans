#include "iostream"
using namespace std;
const int N = 30;

int c[N][N];
bool col[N], dg[N], udg[N];
int n;

void dfs(int u)
{
    if(u==n)
    {
        for (int i = 0; i < n;i++)
            for (int j = 0; j < n;j++)
            if(c[i][j]==1)
                cout << j+1 << " ";
        cout << endl;
        return;
    }
    else
    {
        for (int i = 0; i < n;i++)
        {
            if(!col[i]&&!dg[u+i]&&!udg[u-i+n])
            {
                col[i] = dg[u + i] = udg[n-u + i ] = true;
                c[u][i]=1;
                dfs(u + 1);
                col[i] = dg[u + i] = udg[n- u + i] = false;
                c[u][i] = 0;
            }
        }
    }

}





int main()
{
    cin >> n;
    for (int i = 0; i <= n;i++)
        for (int j = 0; j <= n;j++)
            c[i][j]=0;
    dfs(0);
}