#include "iostream"
using namespace std;

const int N = 1000010;

int a[N], q[N];

int n,k;

int main()
{
    cin >> n;
    cin >> k;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    int hh = 0;//队头
    int tt = -1;//队尾
    for (int i = 0; i < n;i++)
    {
        if(hh<=tt&&q[hh]<i-k+1)
            hh++;
        while(hh<=tt&&a[q[tt]]>=a[i])
            tt--;
        q[++tt] = i;

        if(i>=k-1)
            printf("%d ", a[q[hh]]);
    }
    cout << endl;
    hh = 0;
    tt = -1;
    for (int i = 0; i < n;i++)
    {
        if (hh <= tt&&q[hh]<i-k+1)
            hh++;
        while(hh<=tt&&a[q[tt]]<=a[i])
            tt--;
        q[++tt] = i;
        if(i>=k-1)
            printf("%d ", a[q[hh]]);
    }
}