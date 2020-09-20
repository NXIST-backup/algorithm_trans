#include "iostream"
using namespace std;
int main()
{
    int n;
    int a[100050];
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < n;i++)
    {
        int cnt = 0;
        while(a[i]>0)
        {
            if(a[i]&1)
                cnt++;
            a[i] = a[i]/2;
        }
        printf("%d ", cnt);
    }
}