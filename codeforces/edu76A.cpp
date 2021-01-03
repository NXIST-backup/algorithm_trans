#include<iostream>
using namespace std;
int t;
int n, x, a, b;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> a >> b;

        int dis = max(a, b) - min(a, b)+x;

        if(dis>n-1)
        {
            cout << n - 1 << endl;
        }
        else
            cout << dis << endl;
    }
}