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
vector<int> a;

int main()
{
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        a.push_back(x);
        sum += x;
    }
    sum /= n;

    for(auto item:a){
        item -= sum;
    }
    int flag = 0;
    int l, r = 0;
    int ans = 0;
    for (int i = 0; i < n;i++){
        if(a[i]==0)
            continue;
        else
            flag = a[i];
        while(l!=r){
            ++r, --l;
            if(flag>0){
                if(a[(i+l+n)%n]<0)
                    flag = a[(i + l) % n] + flag;
                if(flag==0)
                    flag=a[(i+l)]
                if(a[(i+r)%n]<0)
                    flag = a[(i + l) % n] + flag;
            }
        }
    }
}