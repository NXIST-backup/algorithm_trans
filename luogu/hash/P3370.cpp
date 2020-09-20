#include "iostream"
#include "cstring"
using namespace std;

typedef unsigned long long ull;

const int N = 20011,P=131;

char str[N];
int idx = 1;
ull h[N], p[N];

int main()
{
    int n;
    cin >> n;
    p[0] = 1;

    for (int i = 1; i <= 1000;i++)
    {
        p[i] = p[i-1] * P;
    }
    int cnt = 0;
    for (int i = 0; i < n;i++)
    {
        str[0] = 1;
        scanf("%s", str + 1);
        ull t=0;
        for (int j = 1; j < strlen(str);j++)
        {
            t += str[j] * p[j - 1];
        }
        bool flag = 1;
        for (int i = 1; i <= idx;i++)
        {
            if(h[i]==t)
            {
                cnt++;
                flag = 0;
                break;
            }
        }
        if(flag)
            h[idx++] = t;
    }

    printf("%d\n", n-cnt);
}