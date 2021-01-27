/*
  Problem Name:Logical Expression
  algorithm tag:
*/

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

const int N = 65;
int n;

int main()
{
    cin >> n;
    string s[N];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    ll zero = 1, one = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == "OR") {
            one <<= 1;
            one += zero;

        } else {
            zero <<= 1;
            zero += one;
        }
    }

    cout << one << endl;
}