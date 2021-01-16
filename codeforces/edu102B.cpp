/*
  Problem Name: String LCM
  algorithm tag: 字符串String
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

int Q;

int main()
{
    cin >> Q;

    while (Q--) {
        string s, t;
        cin >> s >> t;
        if (s.size() < t.size()) {
            string tmp = s;
            s = t;
            t = tmp;
        }
        map<string, int> mp;
        bool flag = true;
        string ju;
        for (int len = 1; len <= t.size(); len++) {
            mp[t.substr(0, len)] = 1;
            flag = true;
            if (t.size() % len != 0 || s.size() % len != 0)
                continue;
            for (int i = 0; i < t.size(); i += len) {
                if (!mp[t.substr(i, len)]) {
                    flag = false;
                    break;
                }
            }
            for (int i = 0; i < s.size(); i += len) {
                if (!mp[s.substr(i, len)]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ju = s.substr(0, len);
                break;
            }
        }

        if (ju.size()) {
            int a = s.size() / ju.size();
            int b = t.size() / ju.size();
            int ans = (a * b) / __gcd(a, b);
            while (ans--)
                cout << ju;
            cout << endl;
        } else
            cout << -1 << endl;
    }
}
