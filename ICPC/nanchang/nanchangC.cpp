#include "iostream"
using namespace std;
int main()
{
    int q;
    int n;
    cin >> n >> q;
    string a;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int flag_8=0;
        int flag_1=0;
        int flag_0=0;
        int flag_2=0;
        for (int i = l; i <= r;i++)
        {
            if(a[i]=='8')
                flag_8 = 1;
            if(a[i]=='1')
                flag_1 = 1;
            if(a[i]=='0')
                flag_0 = 1;
            if(a[i]=='2')
                flag_2 = 1;
        }
        if(flag_0&&flag_1&&flag_2&&flag_8)
            printf("%d", r - l - 3);
        else
            printf("%d", -1);
        }
}