#include "iostream"
#include "algorithm"
#include "set"
#include <set>


using namespace std;
const int N = 1e6 + 19;
int n;
string str[N];
int p[N];

int find(int x)
{
    if(p[x]!=x)
        p[x] = find(p[x]);
    return p[x];
}


int main()
{
    cin >> n;

    for (int i = 0; i < n;i++)
        cin >> str[i];

    for (int i = 1; i <= 1e6;i++)
        p[i] = i;

    for (int i = 0; i < n;i++)
    {
        p[i] = find(str[i][0]);
        for (int j = 0; j < str[i].size();j++)
        {
            p[find(str[i][j])]=find(str[i][0]);
        }
    }
    int ans = 0;
    set<int> vis;

    for (int i = 0; i <= n;i++)
    {
        if(!vis.count(find(i)))
        {
            ans++;
            vis.insert(find(i));
        }
    }
    cout << ans-1 << endl;
}