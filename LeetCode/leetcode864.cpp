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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    vector<int> g[505];
    int dist[505];
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (q.size()) {
            auto t = q.front();
            q.pop();

            auto lnode = t->left;
            if (lnode != NULL) {
                q.push(lnode);
                g[t->val].push_back(lnode->val);
                g[lnode->val].push_back(t->val);
            }
            auto rnode = t->right;
            if (rnode != NULL) {
                q.push(lnode);
                g[t->val].push_back(rnode->val);
                g[rnode->val].push_back(t->val);
            }
        }
        vector<int> ans;
        queue<int> q2;
        q2.push(target->val);
        dist[target->val] = 1;
        while (q2.size()) {
            auto t = q2.front();
            q2.pop();

            if (dist[t] > k + 1)
                break;
            if (dist[t] == k + 1)
                ans.push_back(t);

            for (auto v : g[t]) {
                if (!dist[v]) {
                    q2.push(v);
                    dist[v] = dist[t] + 1;
                }
            }
        }

        return ans;
    }
};
