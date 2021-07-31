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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
  public:
    map<TreeNode *, int> col;
    map<TreeNode *, int> row;
    map<int, vector<TreeNode *>> lis;
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        col[root] = 0;
        row[root] = 0;
        lis[0].push_back(root);
        while (q.size()) {
            auto t = q.front();
            q.pop();

            auto lnode = t->left;
            auto rnode = t->right;

            if (lnode != NULL) {
                col[lnode] = col[t] - 1;
                row[lnode] = row[t] + 1;
                q.push(lnode);
                vector<TreeNode *> tmp;
                while (!lis[col[lnode]].empty()) {
                    auto t = lis[col[lnode]].back();
                    if (row[t] != row[lnode] || t->val <= lnode->val)
                        break;
                    if (t->val > lnode->val) {
                        tmp.push_back(t);
                        lis[col[lnode]].pop_back();
                    }
                }
                lis[col[lnode]].push_back(lnode);
                for (int i = tmp.size() - 1; i >= 0; i--)
                    lis[col[lnode]].push_back(tmp[i]);
            }
            if (rnode != NULL) {
                col[rnode] = col[t] + 1;
                row[rnode] = row[t] + 1;
                q.push(rnode);
                vector<TreeNode *> tmp;
                while (!lis[col[rnode]].empty()) {
                    auto t = lis[col[rnode]].back();
                    if (row[t] != row[rnode] || t->val <= rnode->val)
                        break;
                    if (t->val > rnode->val) {
                        tmp.push_back(t);
                        lis[col[rnode]].pop_back();
                    }
                }
                lis[col[rnode]].push_back(rnode);
                for (int i = tmp.size() - 1; i >= 0; i--)
                    lis[col[rnode]].push_back(tmp[i]);
            }
        }
        vector<pair<int, vector<int>>> list;
        vector<vector<int>> ans;
        for (auto item : lis) {
            vector<int> tmp;
            for (auto v : item.second)
                tmp.push_back(v->val);
            list.push_back({item.first, tmp});
        }
        sort(list.begin(), list.end());

        for (auto item : list)
            ans.push_back(item.second);
        return ans;
    }
};