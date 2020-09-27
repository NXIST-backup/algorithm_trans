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


bool run(int year)
{
    if((year%4==0&&year&100!=0)||year%400==0)
        return true;
    else
        return false;
}
void del(string s,int &month,int &day)
{
    for (int i = 4; i < 6; i++) {
        month += (s[i] - '0') * 10 * (5 - i);
    }
    for (int i = 6; i < 8; i++) {
        day += (s[i] - '0') * 10 * (7 - i);
    }
}
int main()
{
    string a, b;

    cin >> a >> b;

    int a_year, a_month, a_day;
    int b_year, b_month, b_day;

    for (int i = 0; i < 4;i++){
        a_year += (a[i] - '0') * pow(10, (3 - i));
        b_year += (b[i] - '0') * pow(10, (3 - i));
    }
    del(a, a_month, a_day);
    del(b, b_month, b_day);
    if(a_month>0||a_day>0)
        a_year += 1;
    if(b_month>0||b_day>0)
        b_year += 1;
    for (int i = a_year; i <= b_year;i++){
        
    }
}