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

int n;

int main()
{
    cin >> n;

    vector<int> a;

    while(n--){
        int x;
        while(cin>>x){
            a.push_back(x);
        }
    }
    
    sort(a.begin(), a.end());

    for (int i = 0; i < a.size()-1;i++){
        if(a[i+1]==a[i]+2)
            cout << a[i + 1] - 1 << " ";
    }
    for (int i = 0; i < a.size()-1;i++){
        if(a[i+1]==a[i])
            cout << a[i + 1] << " ";
    }
}