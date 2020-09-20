#include "iostream"
using namespace std;

int n;

int main()
{
    cin >> n;
    while(n){
        int stk[10]={0};
        int stk2[10] = {0};
        int tt=1;
        int t = 1;
        int x;
        cin >> x;
        for (int i = 1; x&&i <= n;i++)
        {
            stk[tt] = i;
            stk2[i] = x;
            if(stk[tt]==stk2[t])
            {
                t++;
            }
            else
                tt++;
            if(i>=n)
            {
                if(tt==1)
                    printf("Yes\n");
                else
                    printf("No\n");
                i = 1;
                tt = 1;
                t = 1;
            }
            cin >> x;
        }
            cin >> n;
    }
}