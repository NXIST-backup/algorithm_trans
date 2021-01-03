#include <iostream>
using namespace std;
int main()
{
    long long n, m;
    cin >> n >> m;
    int cnt = 0;
    for (long long i = 0; i <= n; i += m)
    {
        cnt++;
    }
    cout << cnt;
}