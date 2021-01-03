#include "iostream"
using namespace std;

int n, p;

int main()
{
    cin >> n >> p;
    for (int i = 0; i <= 32; i++)
        if (__builtin_popcount(n - i * p) <= i && n - i * p >= i)//__builtin_popcount求二进制1的个数
        {
            cout << i << endl;
            return 0;
        }
    cout << "-1" << endl;
    return 0;
}