/*
  Problem Name:Puzzle From the Future
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

const int N = 1e5 + 5;

int t;
int n;

int main()
{
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> a, b;

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            b.push_back(c - '0');
        }

        a.push_back(1);
        int last = a[0] + b[0];
        for (int i = 1; i < b.size(); i++) {
            if (b[i] + 1 != last)
                a.push_back(1);
            else
                a.push_back(0);
            last = a[i] + b[i];
        }

        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << endl;
    }
}
