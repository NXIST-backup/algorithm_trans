#include "iostream"
using namespace std;
const int N = 100050;
int idx;
int t, n;
char s[N][20];
char str[N];
int cnt[N];
int insert(char str[])
{
    int p = 0;
    int flag=1,flag2=0;
    for (int i = 0; str[i];i++)
    {
        int u = str[i] - '0';
        if(!s[p][u])
        {
            s[p][u] = ++idx;
            flag = 0;
        }
        if(cnt[p])
            flag2 = 1;
        p = s[p][u];
    }
    cnt[p]++;
    if(flag)
        return 1;
    if(flag2)
        return 1;
    return 0;
}
void clear(char str[])
{
    for (int i = 0; i <=idx;i++)
        for (int j = 0; j < 20;j++)
            s[i][j] = 0, cnt[i] = 0;
}
int main()
{
    cin >> t;
    while(t--){
        clear(str);
        idx = 0;
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n;i++)
        {
            cin >> str;
            if(insert(str))
                ans = 1;
        }
        if(ans)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}