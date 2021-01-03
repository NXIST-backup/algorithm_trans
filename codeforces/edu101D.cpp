/*
  Problem Name:Ceil Divisions
  algorithm tag:Math
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

const int N = 2e5 + 5;

int t;
int n;
vector<int> a, b;
int main()
{
    cin >> t;
    a.push_back(2);
    while (t--) {
        cin >> n;
        int cnt = 0;
        int idx = 1;
        while (n) {
            if (idx == 1 || idx == 2) {
                if (idx * 2 >= n) {
                    break;
                } else {
                    idx *= 2;
                    cnt++;
                }
            } else {
                if ((idx * (idx - 1)) >= n) {
                    bool is_valid = true;
                    int temp = n % idx ? n / idx + 1 : n / idx;
                    for (int i = 0; i < a.size(); i++) {
                        if (a[i] == ceil(n / temp))
                            is_valid = false;
                    }
                    if (is_valid)
                        a.push_back(ceil(n / idx));
                    break;
                } else {
                    idx *= (idx - 1);
                    a.push_back(idx - 1);
                    cnt++;
                }
            }
        }
        cout << cnt + (n - 2) << endl;
        int pos = 100;
        b.push_back(1);
        b.push_back(2);
        b.push_back(4);
        b.push_back(12);
        b.push_back(132);
        b.push_back(17292);
        b.push_back(1e9);
        if (n == 3) {
            printf("3 2\n");
            printf("3 2\n");
        } else {
            while (pos) {
                pos = lower_bound(b.begin(), b.end(), n) - b.begin();
                pos--;
                for (int i = b[pos] + 1; i < n; i++)
                    printf("%d %d\n", i, n);
                printf("%d %d\n", n, b[pos]);
                printf("%d %d\n", n, b[pos]);
                if (n == 4)
                    break;
                n = b[pos];
            }
        }
    }
}