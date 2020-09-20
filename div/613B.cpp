#include "iostream"
#include "vector"
using namespace std;


typedef long long  ll;
int t;

const int N = 2e5 + 50;
int a[N];

int main()
{
    cin >> t;

    while (t--) {

        int n = 0;
        cin >> n;
        ll sum = 0;
        ll sum2 = 0;

        for (int i = 1; i <= n;i++)
        {
            cin >> a[i];
        }

        int l = 1, r = n;
        int flag = 1;
        while (l<=r+1) {
            
            if(a[l]+sum>0)
            {
                sum += a[l];
                l++;
            }
            else
            {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
            if(sum2+a[r]>0)
            {
                sum2 += a[r];
                r--;
            }
            else
            {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << "YES" << endl;
    }



        // if(n==2)
        // {
        //     int flag = 1;
        //     for (int i = 1; i <= n;i++)
        //     {
        //         ll x;
        //         cin >> x;
        //         if(x<0)
        //         {
        //             cout << "NO" << endl;
        //             flag = 0;
        //         }
        //     }
        //     if(flag)
        //         cout << "YES" << endl;
        // }
        // else
        // {
        //     for (int i = 1; i <= n;i++)
        //     {
        //         ll x;
        //         cin >> x;
        //         if(x>0)
        //         {
        //             if(i==n)
        //             {
        //                 cout << "YES" << endl;
        //                 break;
        //             }
        //             maxN += x;
        //             continue;
        //         }
        //         else
        //         {
        //             sum += x;
        //             if(i==n||i==1)
        //                 cout << "NO" << endl;
        //             else
        //             {
        //                 if(sum+maxN<=0)
        //                 {
        //                     cout << "NO" << endl;
        //                     break;
        //                 }
        //                 if()
        //             }
        //         }
        //     }
        // }
}