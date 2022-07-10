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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        ListNode *st = NULL, *l = NULL, *last = NULL, *old = NULL;
        auto sss = ListNode();
        st = &sss;
        auto rel_head = st;
        int j = 1;
        int cnt = 0;
        for (auto i = head; i != NULL; i = i->next)
            cnt++;
        cnt = cnt / k * k;
        for (auto i = head; cnt--; j++) {
            old = i->next;
            i->next = last;
            last = i;
            if (j % k == 1)
                l = i;
            if (!(j % k)) {
                l->next = old;
                st->next = i;
                st = l;
            }
            i = old;
        }

        return rel_head->next;
    }
};
