/*
  Problem Name:Message from Aliens 
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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

string s;
deque<char> t;
int main()
{
    iosf;
    cin >> s;
    bool flag = 1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R')
            flag = flag ^ 1;
        else {
            if (flag) {
                if (t.size() && t.back() == s[i])
                    t.pop_back();
                else
                    t.push_back(s[i]);
            } else {
                if (t.size() && t.front() == s[i])
                    t.pop_front();
                else
                    t.push_front(s[i]);
            }
        }
    }
    if (flag)
        while (t.size()) {
            cout << t.front();
            t.pop_front();
        }
    else
        while (t.size()) {
            cout << t.back();
            t.pop_back();
        }
    cout << endl;
    return 0;
}