//使用map映射


#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

const int N=1e5 + 50;

int a[N], b[N], g[N], k[N];
int n;
int x, y;


int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++)
    {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }

    cin >> x >> y;
    int flag = 0;
    int ans = 0;
    for (int i = n; i >= 1;i--)
    {
        if(x<=a[i]+g[i]&&x>=a[i])
        {
            if(y<=b[i]+k[i]&&y>=b[i])
            {
                flag = 1;
                ans = i;
                break;
            }
        }
    }
    if(flag)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
