#include "iostream"
#include "cstring"
#include "vector"
#include <vector>
using namespace std;

int n, k;
string s;
char b[200];
vector<long long> num;//注意数据范围

int main()
{
    cin >> n >> k;

    cin >> s;
    for (int i = 0; i < k;i++)
    {
        char x;
        cin >> x;
        b[x] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < s.size();i++)
    {
        if(!b[s[i]])
        {
            num.push_back(cnt);
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }
    num.push_back(cnt);
    long long ans = 0;
    for(auto item:num)
    {
        ans += (item * (item + 1)) / 2;
    }
    cout << ans << endl;
}