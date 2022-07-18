#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

class WordFilter
{
  public:
    map<string, int> mp[8];
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++) {
            int len = words[i].size();
            for (int j = 1; j <= len; j++) {
                auto sub = words[i].substr(0, i);
                mp[len][sub] = i;
            }
        }
    }

    int f(string pref, string suff)
    {
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
