/*
  Problem Name:魔板
  algorithm tag:状态压缩,最短路
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

map<vector<int>, string> mp;
vector<int> st1, ed;

vector<int> A(vector<int> st)
{
    reverse(st.begin(), st.end());
    return st;
}
vector<int> B(vector<int> st)
{
    swap(st[3], st[0]);
    swap(st[3], st[1]);
    swap(st[3], st[2]);
    swap(st[4], st[7]);
    swap(st[4], st[6]);
    swap(st[4], st[5]);
    return st;
}
vector<int> C(vector<int> st)
{
    swap(st[5], st[2]);
    swap(st[2], st[1]);
    swap(st[1], st[6]);
    return st;
}

int main()
{
    iosf;
    st1 = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 1; i <= 8; i++) {
        int x;
        cin >> x;
        ed.push_back(x);
    }

    queue<vector<int>> q;
    q.push(st1);
    mp[st1].push_back('H');
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (t == ed)
            break;
        auto s1 = A(t);
        auto s2 = B(t);
        auto s3 = C(t);
        if (!mp[s1].size()) {
            mp[s1] = mp[t] + 'A';
            q.push(s1);
        }
        if (!mp[s2].size()) {
            mp[s2] = mp[t] + 'B';
            q.push(s2);
        }
        if (!mp[s3].size()) {
            mp[s3] = mp[t] + 'C';
            q.push(s3);
        }
    }

    auto ans = mp[ed];

    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i];
    }
    puts("");
}