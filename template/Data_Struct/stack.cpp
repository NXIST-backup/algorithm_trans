#include "iostream"
using namespace std;

const int N = 100050;

int stk[N], tt;

int main()
{
    int m;
    cin >> m;
    while(m--){
        string a;
        cin >> a;
        if(a=="push")
        {
            int x;
            cin >> x;
            stk[++tt] = x;//插入
        }
        if(a=="query")
            cout << stk[tt]<<endl;//查询栈头
        if(a=="pop")
            tt--;//弹出
        if(a=="empty")
        {
            if(tt>0)//查询是否为空
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    printf("%d ",stk[tt]);
}