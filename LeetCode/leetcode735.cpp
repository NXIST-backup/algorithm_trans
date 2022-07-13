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

class Solution
{
  public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        int s[10005];
        int h = -1;
        memset(s, 0, sizeof s);
        for (int i = 0; i < asteroids.size(); i++) {
            if ((h < 0 || s[h] < 0) && asteroids[i] < 0) {
                s[++h] = asteroids[i];
                continue;
            }
            if (asteroids[i] > 0) {
                s[++h] = asteroids[i];
                continue;
            }
            if (s[h] > 0 && asteroids[i] < 0) {
                while (h >= 0) {
                    if (s[h] < 0 || asteroids[i] + s[h] >= 0)
                        break;
                    h--;
                }
                if (h < 0 || s[h] < 0)
                    s[++h] = asteroids[i];
                if (s[h] + asteroids[i] == 0)
                    h--;
            }
        }

        for (int i = 0; i <= h; i++)
            ans.push_back(s[i]);

        return ans;
    }
};
int main()
{
    vector<int> as = {10, 2, -5};

    Solution s;
    s.asteroidCollision(as);
}
