#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

void fanfa(vector<int> &number, int cishu)
{
    for (int i = 1; i <= cishu; i++) {
        number.push_back(i);
    }
    std::random_shuffle(number.begin(), number.end());
}
void fanfa2(vector<int> &number, int t, int sum)
{
    int ns = 0;
    for (int i = 0; i < t - 1; i++) {
        ns = rand() % 300 + 1;
        number.push_back(ns);
        sum -= ns;
    }
    number.push_back(sum);
}
int main()
{
    freopen("1.in", "w", stdout);
    srand((unsigned)time(0));

    int n = 100000;
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << 'b';
    cout << endl;

    // int m = 100;
    // for (int i = 1; i <= n; i++) {
    //     int k = rand() % m + 1;
    //     string s;
    //     for (int j = 1; j <= k; j++) {
    //         int flag = rand() % 2 + 1;
    //         char c;
    //         if (flag == 1)
    //             c = rand() % 26 + 65;
    //         else
    //             c = rand() % 26 + 97;
    //         s.push_back(c);
    //     }
    //     cout << s << endl;
    // }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
