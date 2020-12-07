/*
  Problem Name:Subtract or Divide
  algorithm tag:easy
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

int main()
{
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        if(n==1){
            cout << 0 << endl;
            continue;
        }
        if(n==2){
            cout << 1 << endl;
            continue;
        }
        if(n==3){
            cout << 2 << endl;
            continue;
        }
        if(n%2==0)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
}