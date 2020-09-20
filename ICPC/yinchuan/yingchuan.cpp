#include "iostream"
using namespace std;
int main()
{
    int n;
    int a[100050];
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];

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
            int sum=0;
            for (int i = l; i <= r;i++)
                sum += a[i];
            printf("%d\n", sum);
        }
        if(t==2)
        {
            cin >> l >> r >> x;
            for (int i = l; i <= r;i++)
                a[i] ^= x;
        }
        if(t==3)
        {
            cin >> l >> r >> x;
            for (int i = l; i <= r;i++)
                a[i] |= x;
        }
        if(t==4)
        {
            cin >> l >> r >> x;
            for (int i = l; i <= r;i++)
                a[i] &= x;
        }
    }
}