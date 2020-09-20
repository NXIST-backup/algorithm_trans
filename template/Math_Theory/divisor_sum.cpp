//约数之和
//(p1^0+p1^1+p1^2...p1^a1)*(...)*(pk^0+pk^1+...+pk^ak);
//p为质因数，a为指数取值

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
        int p = item.first, a = item.second;
        long long sum = 1;
        while (a--) {
            sum = (sum * p + 1) % maxN;
        }
        res = res * sum % maxN;
    }
    cout << res << endl;
}