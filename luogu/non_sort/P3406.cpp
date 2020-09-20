#include "iostream"
#include "vector"
using namespace std;

int main()
{
    int p[100005]={0};
    int a[100005];
    int b[100005];
    int c[100005];
    int s[100005];
    int n, m;
    cin >> n >> m;
    int pi;
    cin >> pi;
    m--;
    while(m--)
    {
        int flag = pi;
        cin >> pi;
        if(flag>pi)
        {
            p[flag]--;
            p[pi]++;
        }
        else
        {
            p[flag]++;
            p[pi]--;
        }
    }
    for (int i = 1; i <= n;i++)
    {
        s[i] = s[i - 1] + p[i];
    }
    
    
    for (int i = 1; i <= n-1;i++)
    {
        cin >> a[i];

        cin >> b[i];

        cin >> c[i];
    }
    int sum = 0;
    for (int i = 1; i <= n - 1;i++)
    {
        if(s[i]*b[i]+c[i]<a[i]*s[i])
            sum += s[i] * b[i] + c[i];
        else
            sum += a[i] * s[i];
    }
    cout << sum;
}