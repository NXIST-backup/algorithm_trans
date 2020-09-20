#include "iostream"
#include "cstring"
using namespace std;

int ma[10][10];
int temp[10][10];
int n, m, t;
int ans;
int x1, y1, x2, y2;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void dfs(int x,int y)
{
    if(x==x2&&y==y2)
    {
        ans++;
        // for (int i = 1; i <= n;i++)
        // {    
        //     for (int j = 1; j <= n;j++)
        //         cout << ma[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
        return;
    }
    for (int i = 0; i < 4;i++)
    {
        if(!ma[x+dx[i]][y+dy[i]]&&!temp[x+dx[i]][y+dy[i]])
        {
            temp[x + dx[i]][y + dy[i]] = 1;
            dfs(x + dx[i], y + dy[i]);
            temp[x + dx[i]][y + dy[i]] = 0;
        }
    }
}


int main()
{
    cin >> n >> m >> t;


    cin >> x1 >> y1 >> x2 >> y2;
    memset(ma, 4, sizeof ma);
    for (int i = 1; i <= n;i++)
    for(int j=1;j<=m;j++)
        ma[i][j] = 0;
    while(t--){
        int x, y;
        cin >> x >> y;

        ma[x][y] = 4;
    }

    ma[x1][y1] = 4;
    dfs(x1, y1);
    cout << ans << endl;

}