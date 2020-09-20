#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stdio.h>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;
int n, m;
vector<int> path;
map<int, int> st;
void bf(int next)
{
    if(m-path.size()>n-next)//剪
        return;
    if(path.size()==m){
        for(auto item:path){
            printf("%d ", item);
        }
        puts("");
        return;
    }
    for (int i = next+1; i <= n;i++){
        if(!st[i]){
            path.push_back(i);
            st[i] = 1;
            bf(i);
            path.pop_back();
            st[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    bf(0);
}