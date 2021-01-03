#include "iostream"
using namespace std;
int map[1005][1005];
typedef long long ll;
const int mod = 1e9 + 7;
ll ksm(ll a, ll p) {
  ll ans = 1;
  while (p) {
    if (p & 1)
      ans = ans * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return ans;
}
int main()
{
    int x;
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        cin >> x;
        for (int j = 1; j <= x;j++)
            map[i][j] = 1;
        map[i][++x] = -1;
    }
    for (int i = 1; i <= w;i++)
    {
        cin >> x;
        for (int j = 1; j <= x;j++)
        {
            if(map[j][i]==-1)
                return !printf("0\n");
            map[j][i] = 1;
        }
        if(map[++x][i]==1)
            return !printf("0\n");
        map[x][i] = -1;
    }
    // for (int i = 1; i <= h;i++)
    // {
    //     for (int j = 1; j <= w;j++)
    //         cout << map[i][j] << " ";
    //     cout << endl;
    // }
    int ans = 0;
    for (int i = 1; i <= h;i++)
        for (int j = 1; j <= w;j++)
        if(map[i][j]==0)
            ans++;
    cout << ksm(2, ans);
}