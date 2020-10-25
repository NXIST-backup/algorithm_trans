#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

void fanfa(vector<int> &number,int cishu)
{
    for(int i = 1;i<=1000;i++)
    {
        number.push_back(i);
    }
    std::random_shuffle(number.begin(),number.end());
}
void fanfa2(vector<int> &number,int t,int sum)
{
    srand((unsigned)time(0));
    int ns = 0;
    for (int i = 0; i < t - 1;i++){
        ns = rand() % 300+1;
        number.push_back(ns);
        sum -= ns;
    }
    number.push_back(sum);
}

int main()
{
    freopen("10.in","w",stdout);
    int t;
    cin >> t;
    cout << t << endl;
    vector<int> n;
    vector<int> numbers;
    fanfa(n, 1000);
    srand((unsigned)time(0));
    for (int i = 0; i < 100;i++) {
        int s = rand() % 1000 + 1;
        cout << s << endl;
        for (int j = 0; j < s;j++){
            int t = rand() % 10;
            cout << t;
        }
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
