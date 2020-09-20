#include "iostream"

using namespace std;


int main()
{
    int a1;
    int a2;
    int k1;
    int k2;
    int n;
    cin >> a1 >> a2;
    cin >> k1 >> k2;
    cin >> n;
    if(n - (k1 - 1) * a1 - (k2 - 1) * a2>0)
        printf("%d ", n - (k1 - 1) * a1 - (k2 - 1) * a2);
    else
        printf("%d ", 0);
    if(k1>k2)
    {
        int cnt = 0;
        while(n>=k2&&a2--)
        {
            n = n - k2;
            cnt++;
        }
        while(n>=k1&&a1--)
        {
            n = n - k1;
            cnt++;
        }
        printf("%d", cnt);
    }
    else
    {
        int cnt = 0;
        while(n>=k1&&a1--)
        {
            n = n - k1;
            cnt++;
        }
        while(n>=k2&&a2--)
        {
            n = n - k2;
            cnt++;
        }
        printf("%d", cnt);
    }
    
}