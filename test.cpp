/*
  Problem Name:
  algorithm tag:
*/

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
const int mod = 1e9 + 7;
typedef pair<int,int> pii;

int n;


bool cmp1(pii a,pii b){
    if(a.first>b.first)
        return true;
    else if(a.first==b.first){
        if(abs(a.second-n/2)>abs(b.second-n/2))
            return true;
        else
            return false;
    }
    else
        return false;
}
bool cmp2(pii a,pii b){
    if(a.second>b.second)
        return true;
    else if(a.second==b.second){
        if(abs(a.first-n/2)>abs(b.first-n/2))
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    cin >> n;

    vector<pii> a;

    a.push_back({1, 6});
    a.push_back({1, 8});

    sort(a.begin(),a.en)    
}