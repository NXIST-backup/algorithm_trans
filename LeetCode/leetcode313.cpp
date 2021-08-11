/*
  Problem Name:
  algorithm tag:
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed
class Solution
{
  public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        priority_queue<int, vector<int>, greater<int>> heap, heap2;
        heap.push(1);
        for (int i = 0; i < primes.size(); i++)
            heap.push(primes[i]);

        heap2.push(1);
        map<int, bool> mp;
        int cnt = 0;
        int Max = 1e6;
        int Min = min(n * n, Max);
        while (cnt <= Min) {
            int t = heap.top();
            heap.pop();
            if ((ll)t * primes[0] > 1e9)
                break;

            for (int i = 0; i < primes.size(); i++) {
                ll j = (ll)primes[i] * t;
                if (j > 1e9)
                    continue;
                if (mp[j])
                    continue;
                heap.push(j);
                heap2.push(j);
                mp[j] = 1;
                cnt++;
            }
        }
        cnt = 0;
        while (cnt++ < n - 1)
            heap2.pop();
        return heap2.top();
    }
};

int main()
{
    Solution a;
    vector<int> b = {2, 3, 7, 11, 13, 17, 29, 31, 53, 73, 79, 83, 89, 97, 109, 113, 127, 131, 139, 149, 151, 173, 179, 191, 193, 197, 199, 227, 239, 241};
    cout << a.nthSuperUglyNumber(15, b) << endl;
}