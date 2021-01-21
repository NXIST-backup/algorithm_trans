/*
  Problem Name:Cleaning
  algorithm tag:constructive problem(构造题)
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
const int INF = 1e9;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int t;
int n;
int a[N];
int s[N];

int main()
{
    cin >> t;
    int ire = 0;
    while (t--) {
        cin >> n;
        ire++;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int last = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = a[i] - last;
            last = s[i];
        }
        int idx = 1;
        for (int i = n; i > 1; i--) {
            int tmp = s[i];
            if (i % 2 == n % 2)
                tmp -= s[n];
            else
                tmp += s[n];
            if (tmp < 0) {
                idx = i;
                break;
            }
        }
        for (int i = idx; i < n; i++) {
            if (i % 2 == n % 2) {
                if (a[i + 1] - a[i] == -s[n] / 2) {
                    if (s[i] - s[n] / 2 >= 0) {
                        swap(a[i], a[i + 1]);
                        break;
                    } //没把break括进去，卡了好久
                }
            } else {
                if (a[i + 1] - a[i] == s[n] / 2) {
                    if (s[i] + s[n] / 2 >= 0) {
                        swap(a[i], a[i + 1]);
                        break;
                    }
                }
            }
        }
        bool is_valid = true;
        for (int i = 1; i < n; i++) {
            if (a[i + 1] >= a[i]) {
                a[i + 1] -= a[i];
                a[i] = 0;
            } else {
                is_valid = false;
                break;
            }
        }
        if (is_valid && !a[n])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
