#include "iostream"
#include "cmath"
#include "cstring"
using namespace std;

typedef unsigned long long ull;

const int N = 100005,P=131;

pair<ull, ull> h[N];
char dot1[N][25], dot2[N][85];
ull p[N];
int idx = 1;
char str[85];

int main()
{
    int n;
    p[0] = 1;
    for (int i = 1; i < 80;i++)
        p[i] = p[i - 1] * P;
    gets(str);
    while(strcmp(str,"@END@")){
        ull sum = 0;
        int t;
        for (int i = 0;str[i]!=']';i++)
        {
            sum += str[i] * p[i];
            if(i!=0)
            dot1[idx][i-1] = str[i];
            t = i;
        }
        sum += ']' * p[t + 1];
        h[idx].first = sum;
        sum = 0;
        int s = 0;
        for (int i = t + 3; i < strlen(str);i++)
        {
            sum += str[i] * p[s];
            dot2[idx][s++] = str[i];
        }
        h[idx++].second = sum;
        memset(str, 0, sizeof str);
        gets(str);
    }
    cin >> n;
    memset(str, 0, sizeof str);
    gets(str);

    while(n--){
        memset(str, 0, sizeof str);
        gets(str);
        ull sum = 0;
        for (int i = 0; i < strlen(str);i++)
            sum += str[i] * p[i];
        bool flag = 1;
        if (str[0] == '[')
        {
            for (int i = 1; i <= idx; i++)
            {
                if (sum==h[i].first)
                {
                    cout << dot2[i] << endl;
                    flag = 0;
                    break;
                }
            }
            if(flag)
                cout << "what?" << endl;
        }
        else
        {
            for (int i = 1; i <= idx;i++)
            {
                if(sum==h[i].second)
                {
                    cout << dot1[i] << endl;
                    flag = 0;
                    break;
                }
            }
            if(flag)
                cout << "what?" << endl;
        }
    }
}