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
    for(int i = 1;i<=cishu;i++)
    {
        number.push_back(i);
    }
    std::random_shuffle(number.begin(),number.end());
}
void fanfa2(vector<int> &number,int t,int sum)
{

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
    freopen("1.in","w",stdout);
    srand((unsigned)time(0));

    for (int i = 1; i <= 1000;i++) {
        for (int j = 1; j <= 1000;j++)
            cout << 0;
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
