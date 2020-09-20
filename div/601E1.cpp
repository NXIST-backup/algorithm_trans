#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

int n;
const int N = 1e5 + 50;
vector<int> c;
int ma[N];

int main()
{
    cin >> n;
    ma[2] = 1;
    ma[1] = -1;
    for (int i = 3; i <= n;i++)
    {
        for (int j = 2; j <= sqrt(i);j++)
        {
            if(i%j==0)
            {
                ma[i] = 1;
                break;
            }
        }
    }
    int sum = 0, sum2 = 0;
    int temp = 0;
    for (int i = 0; i < n;i++)
    {
        int a;
        cin >> a;
        sum += a;
        if(a)
        {
            sum2 += i - temp;
            c.push_back(i - temp);
            temp = i;
        }
    }

    if(ma[sum])
    {
        cout << sum2 - c[0] << endl;
    }
    else if(ma[sum]==-1)
    {
        cout << -1 << endl;
    }
    else
    {
        
    }
}