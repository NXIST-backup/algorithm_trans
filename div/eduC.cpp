#include "iostream"
#include "algorithm"
#include "vector"
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int t;

bool vis[131][131];
vector<int> g[131];
vector<char> ar;
int st[131];
int ans[131];
int bg = 0;
void dfs(int bg)
{
    st[bg] = 1;
    ar.push_back(bg);
    ans[bg] = 1;
    for (int i = 0; i < g[bg].size();i++)
    {
        if(!st[g[bg][i]])
            dfs(g[bg][i]);
    }
}

 

int main()
{
    cin >> t;


    while (t--) {
        string s;
        cin >> s;
        if(s.size()==1)
        {
            cout << "YES" << endl;
            for (int i = 'a'; i <= 'z';i++)
                printf("%c", i);
            cout << endl;
            continue;
        }
        bool flag = 1;
        memset(vis, 0, sizeof vis);
        memset(st, 0, sizeof st);
        memset(ans, 0, sizeof ans);
        ar.clear();
        for (int i = 'a'; i <= 'z';i++)
        {
            g[i].clear();
        }
        for (int i = 0; i < s.size()-1;i++)
        {
            if(!vis[s[i]][s[i+1]])
            {
                g[s[i]].push_back(s[i + 1]);
                g[s[i + 1]].push_back(s[i]);
                vis[s[i]][s[i + 1]] = 1;
                vis[s[i + 1]][s[i]] = 1;
            }
        }
        for (int i = 'a'; i <= 'z';i++)
        {
            if(g[i].size()==1)
            {
                bg = i;
                flag = 1;
                break;
            }
            else
                flag = 0;
        }
        for (int i = 'a'; i <= 'z';i++)
        {
            if(g[i].size()>2)
                flag = 0;
        }

        if(flag)
        {
            cout << "YES" << endl;
            dfs(bg);
            for(auto item:ar)
            {
                cout << item;
            }
            for (int i = 'a'; i <= 'z';i++)
                if(!ans[i])
                    printf("%c", i);
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
}