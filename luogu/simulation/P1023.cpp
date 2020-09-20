#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

const int N = 25;
int m, n, k;
int p[N][N];
vector<int> s;
map<int, pair<int, int>> ys;
int main()
{
    cin >> m >> n >> k;
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < n;j++)
        {
            int x;
            cin >> x;
            if(x!=0)
            {
                p[i][j] = x;
                ys[x] = {i, j};
                s.push_back(x);
            }
        }
    }
    k -= 2;
    sort(s.begin(), s.end());
    int t = s.back();
    int x = 0, y = ys[t].second;
    int ans = 0;
    while (s.size()) {

        t = s.back();
        s.pop_back();
        int sum = abs(x - ys[t].first) + abs(y - ys[t].second);
        if(k>=sum+ys[t].first+1)
        {
            k -= sum+1;
            x = ys[t].first, y = ys[t].second;
            ans += t;
        }
        else
            break;
    }
    cout << ans << endl;
}