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
const int INF = 1e9;
typedef pair<int,int> pii;

int main()
{
    char c;
    int cnt = 0;
    string s1, s2, s3;
    scanf("%d\n", &cnt);
    c = getchar();
    while(c!='\n'){
        if(cnt==0)
            s1.push_back(c);
        if(cnt==1)
            s2.push_back(c);
        if(cnt==2)
            s3.push_back(c);
        if(c==' ')
            cnt++;
        c = getchar();
    }
    cout << s2 << endl;
}