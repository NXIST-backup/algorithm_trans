#include "iostream"
using namespace std;
const int N = 100050;
int a[N];
int s[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
    {
        s[i] ^= a[i];
        s[i + 1] ^= a[i];
    }
        int m;
    cin >> m;
    while(m--)
    {
        int l, r, x;
        int t;
        cin >> t;
        if(t==1)
        {
            cin >> l >> r;
            printf("%d\n", s[r] - s[l - 1]);
        }
        if(t==2)
        {
            cin >> l >> r >> x;
            s[l] ^= x;
            s[r + 1] ^= x;
        }
        if(t==3)
        {
            cin >> l >> r >> x;
            s[l] |= x;
            s[r + 1] &= 0;
        }
        if(t==4)
        {
            cin >> l >> r >> x;
            s[l] &= x;
            s[r + 1] = s[r + 1] & ~x & 0;
        }
    }
    system("pause");
}   