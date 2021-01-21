/*
  Problem Name:Array Destruction
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
const int INF = 1e9;
typedef pair<int, int> pii;

const int N = 1005 * 2;
const int M = 1e6 + 5;

int t;
int n;

bool cmp(int a, int b)
{
    if (a > b)
        return true;
    else
        return false;
}

int main()
{
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> a;
        map<int, int> st, st2;

        for (int i = 1; i <= 2 * n; i++) {
            int x;
            cin >> x;
            st[x]++;
            a.push_back(x);
        }
        st2 = st;
        sort(a.begin(), a.end(), cmp);
        vector<pii> ans;
        for (int i = 1; i < a.size(); i++) {
            st = st2;
            vector<pii> ans2;
            bool flag = true;
            int x = a[0] + a[i];
            for (int j = 0; j < a.size(); j++) {
                if (st[a[j]] && st[x - a[j]] && st[a[j]] + st[x - a[j]] >= 2) {
                    ans2.push_back({a[j], x - a[j]});
                    st[a[j]]--;
                    st[x - a[j]]--;
                    x = a[j];
                }
            }
            for (auto &kv : st)
                if (kv.second)
                    flag = false;
            if (flag) {
                ans = ans2;
                break;
            }
        }
        if (ans.size()) {
            cout << "YES" << endl;
            cout << ans[0].first + ans[0].second << endl;
            for (auto item : ans)
                cout << item.first << " " << item.second << endl;
        } else
            cout << "NO" << endl;
    }
}