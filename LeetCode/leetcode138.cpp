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

// Definition for a Node.
class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        vector<Node *> list;
        vector<Node> nlist;

        for (auto i = head;; i = i->next) {
            list.push_back(i);
            Node a = *i;
            nlist.push_back(a);
            if (i->next == NULL)
                break;
        }
        int idx = 0;
        for (auto i = *head;; i = *(i.next)) {
            if (i.next != NULL)
                nlist[idx].next = &nlist[idx + 1];
            else
                nlist[idx].next = NULL;
            int tmp = -1;
            for (int j = 0; j < list.size(); j++)
                if (i.random == list[j]) {
                    tmp = j;
                    break;
                }
            if (tmp == -1)
                nlist[idx].random = NULL;
            else
                nlist[idx].random = &nlist[tmp];
            idx++;
            if (i.next == NULL)
                break;
        }

        return &nlist[0];
    }
};

int main()
{
    Solution s;
    Node a(7), b(13), c(11), d(10), e(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    b.random = &a;
    c.random = &e;
    d.random = &c;
    e.random = &a;
    cout << s.copyRandomList(&a) << endl;
}