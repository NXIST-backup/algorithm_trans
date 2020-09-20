#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100005];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int cnt = 1;
    int max = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            cnt++;
        }
        else
        {
            if (cnt > max)
                max = cnt;
            cnt = 1;
        }
    }
    if (cnt > max)
        max = cnt;
    printf("%d", max);
}