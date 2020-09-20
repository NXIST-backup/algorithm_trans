//hash_string

#include "iostream"
#include "cstring"
using namespace std;

typedef unsigned long long ull;

const int N = 30003,P=131;

char str[205];
ull h[N], p[N];
int n,idx=1;

int main()
{
    cin >> n;
    p[0] = 1;
    for (int i = 1; i <= 200;i++)
        p[i] = p[i - 1] * P;
    while (n--)
    {
        char op[5];
        cin >> op;

        if (op[0] == 'a')
        {
            gets(str);

            for (int i = 0; i < strlen(str);i++)
            {
                h[idx] += p[i]*str[i];
            }
            idx++;
        }
        else
        {
            int flag = 1;
            ull sum=0;
            gets(str);
            for (int i = 0; i < strlen(str);i++)
                sum += str[i] * p[i];
            for (int i = 1; i <= idx;i++)
            if(sum==h[i])
            {
                cout << "yes" << endl;
                flag = 0;
                break;
            }
            if(flag)
                cout << "no" << endl;
        }
    }
}