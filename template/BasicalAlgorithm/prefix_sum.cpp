//前缀和是降低时间复杂度的方式，
//主要是减少查询的时间复杂度
//如果是纯循环时间复杂度O（n*m）m次查询
//前缀和时间复杂度O(n+m) m次查询

#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[100050];
    int s[100050];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    s[0] = 0;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    while (m--) {
        int l, r;
        cin >> l >> r;
        printf("%d\n", s[r] - s[l - 1]);
    }
}