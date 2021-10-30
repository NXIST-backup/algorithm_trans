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
#define iosf ios::sync_with_stdio(true), cin.tie(0), cout << fixed
class Solution
{
  public:
    bool isSelfCrossing(vector<int> &distance)
    {
        if (distance.size() < 4)
            return false;
        if (distance.size() == 4)
            return distance[2] - distance[0] <= 0 && distance[3] - distance[1] >= 0;
        pair<int, int> p[4], now;
        p[0] = {distance[3] - distance[1], distance[0] - distance[2]};
        p[1] = {0, distance[0]};
        p[2] = {-distance[1], distance[0]};
        p[3] = {-distance[1], distance[0] - distance[2]};
        now = p[3];
        if (distance[3] - distance[1] > 0) {
            for (int i = 4; i < distance.size(); i++) {
                if (i % 4 == 0) {
                    if (now.first)
                }
            }
        }
    }
};
int main()
{
    vector<int> distance = {1, 1, 2, 2, 1, 1};
    Solution s;
    s.isSelfCrossing(distance);
}