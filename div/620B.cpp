#include "iostream"
#include "vector"
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
string s[150];
string c[150];
vector<int> huiwen;
vector<int> zihui;
bool st[150];
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n;i++)
    {
        cin >> s[i];
        c[i] = s[i];
    }

    for (int i = 1; i <= n;i++)
    {
        reverse(c[i].begin(), c[i].end());
        for (int j = 1; j <= n;j++)
        {
            if(c[i]==s[j]&&i!=j&&!st[i]&&!st[j]&&c[i]!=s[i])
            {
                huiwen.push_back(i);
                st[i] = true;
                st[j] = true;
            }
        }
    }

    for (int i = 1; i <= n;i++)
    {
        if(c[i]==s[i])
            zihui.push_back(i);
    }
    sort(zihui.begin(), zihui.end());
    int flag = 0;
    int max = 0;
    int cnt = 1;
    for (int i = 0; i < zihui.size();i++)
    {
        if(i!=zihui.size()-1&&s[zihui[i]]==s[zihui[i+1]])
        {
            cnt++;
        }
        else
        {
            if(cnt>max)
            {
                max = cnt;
                flag = zihui[i];
            }
            cnt = 1;
        }
    }

    cout << huiwen.size() * m * 2 + max * m << endl;

    for(auto item:huiwen)
    {
        cout << s[item];
    }
    for (int i = 0; i < max;i++)
    {
        cout << s[flag];
    }
    for (int i = huiwen.size() - 1; i >= 0;i--)
    {
        reverse(s[huiwen[i]].begin(), s[huiwen[i]].end());
        cout << s[huiwen[i]];
    }
}