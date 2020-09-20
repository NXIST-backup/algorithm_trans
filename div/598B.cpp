#include "iostream"
#include "cstring"
using namespace std;

int q;
int n;
const int N = 105;
int a[N];
int main()
{
    cin >> q;
    while(q--){

        cin >> n;
        bool op[N];
        memset(op, 0, sizeof op);
        for (int i = 1; i <= n;i++)
            cin >> a[i];

        for (int i = n; i >= 1;i--)
        {
            if(a[i]<a[i-1]&&i!=1)
            {
                swap(a[i], a[i - 1]);
                op[i] = 1;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if(op[i]==0)
            {
                if(a[i]<a[i-1])
                    {
                        swap(a[i], a[i - 1]);
                        op[i] = 1;
                    }
            }
        }
        for (int i = 1; i <= n;i++)
            cout << a[i] << " ";
        puts("");
    }
}