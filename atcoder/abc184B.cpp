/*
  Problem Name:Quizzes
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

string s;
int n, x;

int main()
{
    cin >> n >> x;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'o')
            x++;
        else {
            if (x != 0)
                x--;
        }
    }
    cout << x << endl;
}