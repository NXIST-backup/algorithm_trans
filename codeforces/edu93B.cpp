#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

int t;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> t;
    while (t--) {

        string s;
        cin >> s;
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                cnt++;
            } else {
                if (cnt > 0)
                    ans.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt > 0)
            ans.push_back(cnt);
        int res = 0;
        sort(ans.begin(),ans.end(),cmp);
        // for (auto item : ans) {
        //     cout<<item<<" ";
        // }
        // cout << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i % 2 == 0)
                res+=ans[i];
        }
        cout << res << endl;
    }
}