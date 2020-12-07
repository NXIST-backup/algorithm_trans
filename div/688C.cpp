/*
  Problem Name:Triangles
  algorithm tag:implement
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

const int N = 1e3 + 5;

int n;
int t;
//我的代码时间复杂度冗余太多了，没优化。
int main()
{
    cin >> t;

    while (t--) {
        cin >> n;
        vector<pii> a[10];
        for (int i = 1; i <= n; i++) {
            vector<pii> b[10];
            for (int j = 1; j <= n; j++) {
                char c;
                cin >> c;
                b[c - '0'].push_back({i, j});
            }
            for (int j = 0; j <= 9;j++){
                if(b[j].size()){
                    a[j].push_back({b[j][0].first,b[j][0].second});
                    if(b[j].size()>=2)
                        a[j].push_back({b[j].back().first,b[j].back().second});
                }
            }
        }

        for (int i = 0; i <= 9;i++){
            int maxv = 0;
            for (int j = 0; j < a[i].size();j++){
                for (int k = j + 1; k < a[i].size();k++){
                    int x1 = a[i][j].first, y1 = a[i][j].second;
                    int x2 = a[i][k].first, y2 = a[i][k].second;
                    maxv = max(maxv, max(x1 - 1, n - x1) * abs(y2 - y1));
                    maxv = max(maxv, max(x2 - 1, n - x2) * abs(y2 - y1));
                    maxv = max(maxv, max(y1 - 1, n - y1) * abs(x2 - x1));
                    maxv = max(maxv, max(y2 - 1, n - y2) * abs(x2 - x1));
                }
            }
            cout << maxv << " ";
        }
        cout << endl;
    }
}