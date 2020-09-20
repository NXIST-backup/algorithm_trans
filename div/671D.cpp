//简单的排序题
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
const int INF = 1e9;
typedef pair<int, int> pii;

int n;

int main()
{
    cin >> n;

    vector<int> s, a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        if (i < n / 2)
            a.push_back(s[i]);
        else
            b.push_back(s[i]);
    }

    if(n<3){
        cout<<0<<endl;
        for(auto item:s){
            cout << item << " ";
        }
        cout << endl;
        return 0;
    }
    s.clear();
    for (int i = 0; i < b.size(); i++) {
        s.push_back(b[i]);
        if(i<a.size())
            s.push_back(a[i]);
    }
    int ans = 0;
    for (int i = 1; i < s.size()-1;i+=2) {
        if(s[i-1]>s[i]&&s[i+1]>s[i])
            ans++;
    }

    if(n>=3){
        cout << ans << endl;
        for(auto item:s)
            cout << item << " ";
        cout << endl;
    }
}