/*
  Problem Name:最小好进制
  algorithm tag:math 
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

class Solution
{
  public:
    string smallestGoodBase(string n)
    {
        long long p = 1, nn = 0;
        for (int i = n.size() - 1; i >= 0; i--) {
            nn += (n[i] - '0') * p;
            if (p < 1e18)
                p *= 10;
        }
        long long ans = nn - 1;
        for (int i = 2; i <= 59; i++) {
            long long st = pow(nn, 1.0 / i);
            if (st > 1) {
                long long tmp = nn;
                bool is_valid = true;
                while (tmp) {
                    if (tmp % st != 1) {
                        is_valid = false;
                        break;
                    }
                    tmp /= st;
                }
                if (is_valid) {
                    ans = st;
                    break;
                }
            }
        }
        string res = to_string(ans);
        return res;
    }
};

int main()
{
    string n;
    cin >> n;
    Solution s;
    s.smallestGoodBase(n);
}