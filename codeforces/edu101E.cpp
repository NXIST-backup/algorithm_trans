#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
const int MAX = 20;
char s[maxn];
bool vis[1 << MAX];
int cnt[maxn];
vector<int> rec;
void work(int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; ++i) {
        ans = ans * 2 + !(s[i] - '0');
    }
    if (!vis[ans])
        rec.push_back(ans);
    vis[ans] = true;
}
vector<int> as;
bool flag = false;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d%s", &n, &k, s + 1);
        for (int i = 1; i <= n; ++i) {
            cnt[i] = cnt[i - 1] + (s[i] == '0');
        }
        for (int i = 1; i <= n - k + 1; ++i) {
            if (k > MAX && cnt[i + k - MAX - 1] - cnt[i - 1] >= 1) {
                continue;
            }
            work(max(i + k - MAX, i), i + k - 1);
        }
        for (int i = 0; i < (1 << min(MAX, k)); ++i) {
            if (!vis[i]) {
                for (int j = 1; j <= k - min(MAX, k); ++j) {
                    as.push_back(0);
                }
                for (int j = min(MAX - 1, k - 1); j >= 0; --j) {
                    if ((1 << j) & i) {
                        as.push_back(1);
                    } else
                        as.push_back(0);
                }
                break;
            }
        }
        for (int i = 0; i < rec.size(); ++i) {
            vis[rec[i]] = false;
        }
        rec.clear();
        if (as.empty())
            printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 0; i < as.size(); ++i)
                printf("%d", as[i]);
            puts("");
            as.clear();
        }
    }
}
