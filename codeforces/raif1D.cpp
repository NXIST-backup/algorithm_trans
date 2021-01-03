#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

const int N = 1e5 + 5;
int n;
vector<pii> pos;
int col[N], row[N];

bool cmp(pii a,pii b)
{
    if(a.second>b.second)
        return true;
    else
        return false;
}
int main()
{
    cin >> n;

    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        pos.push_back({x, i + 1});
    }
    vector<pii> ans;
    queue<pii> q1,q2,q3;
    sort(pos.begin(), pos.end(), cmp);
    int idx = 1;
    for(auto item:pos){
        if(item.first==1){
            q1.push({idx, item.second});
            ans.push_back({idx++, item.second});
        }
        if(item.first==2){
            if(q1.size()==0){
                cout << -1 << endl;
                return 0;
            }
            auto t = q1.front();
            q1.pop();
            q2.push({t.first, item.second});
            ans.push_back({t.first, item.second});
        }
        if(item.first==3){
            if(q3.size()){
                auto t = q3.front();
                q3.pop();
                ans.push_back({idx, item.second});
                q3.push({idx, item.second});
                ans.push_back({idx++, t.second});
            }
            else if(q2.size()){
                auto t = q2.front();
                q2.pop();
                ans.push_back({idx, item.second});
                q3.push({idx, item.second});
                ans.push_back({idx++, t.second});
            }
            else if(q1.size()){
                auto t = q1.front();
                q1.pop();
                ans.push_back({idx, item.second});
                q3.push({idx, item.second});
                ans.push_back({idx++, t.second});
            }
            else{
                cout << -1 << endl;
                return 0;
            }
        }

    }
    cout << ans.size() << endl;
    for(auto item:ans){
        cout << n - item.first + 1 << " " << item.second << endl;
    }
}