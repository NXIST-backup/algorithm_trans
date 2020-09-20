//求约数个数
//(a1+1)(a2+1)....a(k+1)
//a为质因数的指数次数
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;
const int maxN=1e9+7;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> prime;
    while (n--) {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i;i++)
        while (x%i==0) {
            x /= i;
            prime[i]++;
        }
        if(x>1)
            prime[x]++;
    }

    long long res = 1;
    for(auto item:prime)
    {
        res = res * (item.second + 1) % maxN;
    }
    cout << res << endl;
}