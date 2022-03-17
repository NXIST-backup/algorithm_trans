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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

class AllOne
{
  public:
    unordered_map<string, int> mp;
    set<pair<int, string>> st;
    AllOne()
    {
    }
    void inc(string key)
    {
        st.erase({mp[key], key});
        mp[key]++;
        st.insert({mp[key], key});
    }

    void dec(string key)
    {
        st.erase({mp[key], key});
        mp[key]--;
        if (mp[key] > 0) {
            st.insert({mp[key], key});
        }
    }

    string getMaxKey()
    {
        if (st.empty())
            return "";
        else
            return (*--st.end()).second;
    }

    string getMinKey()
    {
        if (st.empty())
            return "";
        else
            return (*st.begin()).second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */