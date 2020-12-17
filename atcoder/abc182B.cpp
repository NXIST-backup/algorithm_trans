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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

int a[105];
int n;
set<int> gc;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    int ansval = 0;
    for (int i = 2; i <= 1000; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] % i == 0)
                cnt++;
        }
        if (ans < cnt) {
            ansval = i;
            ans = cnt;
        }
    }

    cout << ansval << endl;
}