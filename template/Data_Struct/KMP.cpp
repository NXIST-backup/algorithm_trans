#include "iostream"
using namespace std;
const int N = 10010, M = 100010;
int n, m;
char p[N], s[M];
int ne[N];
int main()
{
    cin >> n;
    cin >> (p + 1);
    cin >> m;
    cin >> (s + 1);
    //时间复杂度为 O(2m)
    //求next过程(求p串中，以p[i]结尾的后缀，能够匹配的从一开始的前缀的最大长度)
    for (int i = 2, j = 0; i <= n; i++) //i是后缀下标
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[j + 1] == p[i]) // p="abababab"
            j++;              //    12345678
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++) {
        //匹配过程
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n) {
            printf("%d ", i - n);
            j = ne[j]; //匹配成功
        }
    }
    return 0;
}