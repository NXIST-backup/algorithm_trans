#include "iostream"
#include "vector"
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;
    int flag = 1;
    for (; l <= r;l++)
    {
        if(l<=10)
        {
            cout << l;
            flag = 0;
            break;
        }
        if(l>10&&l<100)
        {
            if(l/10!=l%10)
            {
                cout << l;
                flag = 0;
                break;
            }
        }
        if(l>100&&l<1000)
        {
            int a1 = l / 100;
            int a2 = (l % 100) / 10;
            int a3 = l % 10;
            if(a1!=a2&&a2!=a3&&a3!=a1)
            {
                cout << l;
                flag = 0;
                break;
            }
        }
        if(l>1000&&l<10000)
        {
            int a1 = l / 1000;
            int a2 = (l % 1000) / 100;
            int a3 = (l % 100) / 10;
            int a4 = l % 10;
            if (a1 != a2&&a1!=a3&&a1!=a4&&a2!=a3&&a2!=a4&&a3!=a4)
            {
                cout << l;
                flag = 0;
                break;
            }
        }
        if(l>10000&&l<100000)
        {
            int a1 = l / 10000;
            int a2 = (l % 10000) / 1000;
            int a3 = (l % 1000) / 100;
            int a4 = (l % 100) / 10;
            int a5 = l % 10;
            if(a1!=a2&&a1!=a3&&a1!=a4&&a1!=a5&&a2!=a3&&a2!=a4&&a2!=a5&&a3!=a4&&a3!=a5&&a4!=a5)
            {
                cout << l;
                flag = 0;
                break;
            }
        }
    }
    if(flag)
        cout << -1;
}