#include "iostream"
#include <cstring>
using namespace std;
const int N = 10010, M = 100010;
int n, m;
char p[N], s[M];
int ne[N];
int main()
{
    cin >> s + 1;
    cin >> p + 1;
    n = strlen(p+1);
    m = strlen(s+1);
    //时间复杂度为 O(2m)
    //求next过程(求p串最大相同前缀和后缀不大于i)
    for (int i = 2, j = 0; i <= n;i++)
    {
        while(j&&p[i]!=p[j+1])
            j = ne[j];
        if(p[j+1]==p[i])// p="abababab"
            j++;        //    12345678  
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m;i++)
    {

            //匹配过程
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if(s[i]==p[j+1])
            j++;
        if(j==n)
        {
            printf("%d\n", i - n+1);
            j = ne[j]; //匹配成功
        }
    }
    for (int i = 1; i <= n;i++)
        cout << ne[i] << " ";
    return 0;
}