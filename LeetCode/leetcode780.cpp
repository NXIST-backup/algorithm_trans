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
const int INF = 1e9;
typedef pair<int, int> pii;
class Solution
{
  public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> mp = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> st;

        for (int i = 0; i < words.size(); i++) {
            string s;
            for (int j = 0; j < words[i].size(); j++) {
                s += mp[words[i][j] - 'a'];
            }
            st.insert(s);
        }

        return st.size();
    }
};
