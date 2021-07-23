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

class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans;
        queue<TreeNode> q;
        auto rr = *root;
        q.push(rr);
        string tmp = to_string(rr.val);
        ans += tmp;
        ans.push_back(',');
        while (q.size()) {
            auto rt = q.front();
            q.pop();

            auto l = rt.left, r = rt.right;
            if (l != NULL) {
                auto le = *l;
                string s = to_string(le.val);
                ans += s;
                ans.push_back(',');
            } else
                ans += "NULL,";
            if (r != NULL) {
                auto re = *r;
                string s = to_string(re.val);
                ans += s;
                ans.push_back(',');
            } else
                ans += "NULL,";
        }

        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> list;
        list.push_back("aaaaa");
        string s;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] != ',')
                s.push_back(data[i]);
            else {
                list.push_back(s);
                s.clear();
            }
        }
    }
};
//
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main()
{
    Codec a;
    string ans, res;
    res.push_back('"');
    res += "NULL";
    res.push_back('"');
    for (int i = 0; i < 4; i++)
        ans += res;
    a.deserialize(ans);
}