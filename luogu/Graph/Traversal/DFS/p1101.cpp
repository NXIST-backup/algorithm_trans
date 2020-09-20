#include "iostream"
#include "vector"
using namespace std;

const int N = 105;

int n;
vector<pair<int, int>> num_y;
char a[N][N];
bool d[N][N];
int dx[8]{1, 0, -1, 0, 1, -1, 1, -1}, dy[8]{0, 1, 0, -1, 1, -1, -1, 1};
string ans = "yizhong";
int idx = 0;

void dfs()
{
    if(idx+1==7)
    {
        
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='y')
                num_y.push_back({i, j});
        }

}