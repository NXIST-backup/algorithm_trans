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

const int N = 1e6 + 5;

int n;
int cnt1, cnt2;
double tprs[N], fprs[N];
vector<int> list, po, ne;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char c;
        int x;
        scanf("%c%d", &c, &x);
        if (c == '+')
            po.push_back(x);
        else
            ne.push_back(x);
        list.push_back(x);
    }
    sort(list.begin(), list.end());
    sort(po.begin(), po.end());
    sort(ne.begin(), ne.end());
    int idx = 0;
    for (int i = 0; i < list.size(); i++) {
        int key = list[i];
        int fn = lower_bound(po.begin(), po.end(), key) - po.begin();
        int tp = po.size() - fn;
        int tn = lower_bound(ne.begin(), ne.end(), key) - ne.begin();
        int fp = ne.size() - tn;
        tprs[++idx] = tp / (double)(tp + fn);
        fprs[idx] = fp / (double)(tn + fp);
    }

    double ans = 0;

    for (int i = 1; i < idx; i++)
        ans += (fprs[i] - fprs[i + 1]) * tprs[i + 1];

    printf("%.10lf", ans);
}