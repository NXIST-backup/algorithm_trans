/*
  Problem Name:
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
int a[N * 2];
int n, k;
int t;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;

        int recur = 2 * k - 1 - n;

        for (int i = 1; i <= recur; i++) {
            cout << i << " ";
        }
        for (int i = k; i >= recur + 1; i--) {
            cout << i << " ";
        }
        cout << endl;
    }
}