#include "iostream"
using namespace std;
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    int a[100050], b[100050];
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < m;i++)
        cin >> b[i];
    for (int i = 0, j = m-1; i < n;i++)
    {
        while (j >= 0&&a[i]+b[j]>x)
            j--;
        if(j>=0&&a[i]+b[j]==x)
            printf("%d %d", i, j);
    }
}