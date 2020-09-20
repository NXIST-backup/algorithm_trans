#include "iostream"
using namespace std;
int main()
{
    int stk[10]={0};
    int n;
    int cnt = 0;
    cin >> n;
    int op;
    while(n--){
        cin >> op;
        int x;
        if(op==0)
        {
            cin >> x;
            if(x>=stk[cnt])
            stk[++cnt] = x;
            else
            {
                int t = stk[cnt];
                stk[++cnt] = t;
            }
        }
        if(op==1)
        {
            cnt--;
        }
        if(op==2)
        {
            printf("%d\n", stk[cnt]);
        }
    }
}