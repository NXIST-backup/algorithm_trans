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
    TreeNode *pruneTree(TreeNode *root)
    {
        bool flag = dfs(root);
        if (!flag)
            root = NULL;
        return root;
    }
    bool dfs(TreeNode *node)
    {
        bool flag1 = false, flag2 = false;
        if (node->left && dfs(node->left))
            flag1 = true;
        else
            node->left = NULL;
        if (node->right && dfs(node->right))
            flag2 = true;
        else
            node->right = NULL;
        return flag1 || flag2 || node->val;
    }
};
