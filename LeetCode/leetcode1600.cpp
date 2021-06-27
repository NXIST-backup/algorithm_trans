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
class ThroneInheritance
{
  public:
    vector<string> g[100005];
    map<string, int> mp;
    map<string, bool> deth;
    int idx;
    vector<string> ans;
    string kn;
    ThroneInheritance(string kingName)
    {
        idx = 0;
        mp[kingName] = ++idx;
        kn = kingName;
    }

    void birth(string parentName, string childName)
    {
        mp[childName] = ++idx;
        g[mp[parentName]].push_back(childName);
    }

    void death(string name)
    {
        deth[name] = true;
    }
    void dfs(int u)
    {
        for (auto v : g[u]) {
            if (!deth[v])
                ans.push_back(v);
            dfs(mp[v]);
        }
    }
    vector<string> getInheritanceOrder()
    {
        ans.clear();
        if (!deth[kn])
            ans.push_back(kn);
        dfs(1);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */