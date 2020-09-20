#include "iostream"
using namespace std;
int main()
{
    char c;
    int ans = 0;
    int cnt = 0;
    c = getchar();
    while(c!='\n'&&c!=EOF)
    {
        if(c=='(')
            cnt++;
        if(c==')'&&cnt)
        {
            cnt--;
            ans += 2;
        }
        c = getchar();
    }
    cout << ans;
}