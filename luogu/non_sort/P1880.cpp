#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<pair<int, int>> alls;

void merge(vector<pair<int, int>> &segs)
{
    int l = -2e9;
    int r = -2e9;
    vector<pair<int, int>> ans;
    sort(segs.begin(), segs.end());
    for(auto seg:segs)
    {
        if(r<seg.first)
        {
            if(l!=-2e9)
                ans.push_back({l, r});
            l = seg.first, r = seg.second;
        }
        else
            r = max(r, seg.second);
    }
    if(l!=-2e9)
        ans.push_back({l, r});
    segs = ans;
}

int main()
{

    int n;
    cin >> n;
    while(n--)
    {
        int l, r;
        cin >> l >> r;
        alls.push_back({l, r});
    }
    merge(alls);
    int sum = 0;
    for(auto item:alls)
    {
        sum = sum+item.second - item.first;
    }
    cout << sum;
}