/*
  Problem Name:1-SAT
  algorithm tag:string hash
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

const int N = 2e5 + 5;

map<string, pii> mp;

int n;

int main()
{
    cin >> n;
    string ans;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1;
        if (s1[0] == '!') {
            for (int i = 1; i < s1.size(); i++)
                s2.push_back(s1[i]);
            mp[s2].second = 1;
            if (mp[s2].first && mp[s2].second) {
                ans = s2;
            }
        } else {
            mp[s1].first = 1;
            if (mp[s1].first && mp[s1].second) {
                ans = s1;
            }
        }
    }
    if (ans.size())
        cout << ans << endl;
    else
        cout << "satisfiable" << endl;
}
