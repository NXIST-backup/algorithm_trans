#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int n;
    int a[150005];
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < a[i + 1])
                ans++;
        }
        if (n == 1)
            printf("0\n");
        else
            printf("%d\n", ans);
    }
}