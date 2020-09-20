//按区间左端点排序
//pair优先左端点排序再右端点排序
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
const int N = 100050;
int n;
vector<pair<int, int>> segs;

void merge(vector<pair<int, int>> &segs)
{
    int l = -2e9;
    int r = -2e9;
    vector<pair<int, int>> ans;
    sort(segs.begin(), segs.end());
    for (auto seg : segs) {
        if (r < seg.first) {
            if (l != -2e9)
                ans.push_back({l, r});
            l = seg.first, r = seg.second;
        } else
            r = max(r, seg.second);
    }
    if (l != -2e9)
        ans.push_back({l, r});
    segs = ans;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
}