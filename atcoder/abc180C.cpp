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
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

int main()
{
    ll n;

    cin >> n;
    vector<ll> ans;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i)
                ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());

    for (auto item : ans)
        cout << item << endl;
}