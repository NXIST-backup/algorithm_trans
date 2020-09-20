#include "iostream"
#include "algorithm"
#include "cstring"
#include "vector"

using namespace std;
typedef unsigned long long ull;
int t;

ull n, g, b;


int main()
{
    cin >> t;

    while (t--) {

        cin >> n >> g >> b;
        ull mid = 0;
        ull ned = 0;
        if(n%(2*g))
            ned = n / 2 / g+1;
        else
            ned = n / 2 / g;
        if(n%2)
            mid = n / 2 + 1;
        else
            mid = n / 2;
        unsigned long long sum = 0;
        if(ned*(g+b)<n)
            cout << n << endl;
        else
        {
            if(g>n)
                sum = ned * (g + b) - b - (ned * g - n);
            else
                sum = ned * (g + b) - b - (ned * g - mid);
            cout<<sum<<endl;
        }
    }
}