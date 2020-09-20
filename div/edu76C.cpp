#include "iostream"
#include "cstring"
using namespace std;
int t;
int n;
const int N = 2e5 + 50;
int a[N];
int st[N];

int main()
{
    cin >> t;
    while (t--) {
        int min2 = 1e9 + 10;
        memset(st, 0, sizeof st);
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> a[i];

        for (int i = 1; i <= n;i++)
        {
            if(!st[a[i]])
            {
                st[a[i]] = i;
            }
            else
            {
                int x = i - st[a[i]] + 1;
                if(min2>x)
                    min2 = x;
                st[a[i]] = i;
            }
        }

        if(min2!=1e9+10)
            cout << min2<< endl;
        else
            cout << -1 << endl;
    }
}