#include "iostream"
#include "math.h"
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    while(n){
        int x = (n - 1940) / 10;
        x = pow(2, x);
        int sum = 0;
        while(x--!=-1)
        {
            sum += pow(2, x);
        }
        int cnt = 1;
        int i;
        for ( i = 1; cnt < sum;i++)
        {
            cnt *= i;
        }
        cout << i-2 << endl;
        cin >> n;
    }
}