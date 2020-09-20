#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

string a;
map<string, int> st;
int maxN;
int main()
{
    cin >> a;

    for (int i = 0; i < a.size();i++)
    {
        string s;
        s.push_back(a[i]);
        st[s]++;
        if(st[s]>maxN)
            maxN = st[s];
    }
    if(a.size()>=2)
    {
        for (int i = 0; i < a.size();i++)
        {
            for (int j = i + 1; j < a.size();j++)
            {
                string s;
                s.push_back(a[i]);
                s.push_back(a[j]);
                st[s]++;
                if(st[s]>maxN)
                    maxN = st[s];
            }
        }
    }
    cout << maxN << endl;
}