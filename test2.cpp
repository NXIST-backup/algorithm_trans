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

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ans = 0;
int depth[30], dp[30];
int eating(TreeNode *root)
{
    queue<pair<TreeNode *, int>> q;
    depth[1] = root->val;
    q.push({root, 1});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        depth[t.second] += t.first->val;
        if (!root->left)
            q.push({root->left, t.second + 1});
        if (!root->right)
            q.push({root->right, t.second + 1});
    }
    int ans = 0;
    int res = 0;
    for (int i = 1; i <= 28; i += 2)
        ans += depth[i];
    for (int i = 2; i <= 28; i += 2)
        res += depth[i];
    ans = max(res, ans);
    return ans;
}
