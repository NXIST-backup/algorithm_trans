/*
  Problem Name:
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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

string word, ans1, ans2;
map<string, bool> mp1, mp2;
vector<string> pre, suf;
void init()
{
    mp1["anti"] = true;
    mp1["post"] = true;
    mp1["pre"] = true;
    mp1["re"] = true;
    mp1["un"] = true;
    mp2["re"] = true;
    mp2["gni"] = true;
    mp2["ezi"] = true;
    mp2["noit"] = true;
    mp2["luf"] = true;
}

int main()
{
    iosf;
    cin >> word;
    init();
    string rev_word = word;
    reverse(rev_word.begin(), rev_word.end());
    string tmp;

    for (int i = 0; i < word.size(); i++) {
        tmp.push_back(word[i]);
        if (mp1[tmp])
            pre.push_back(tmp), tmp.clear();
        else
            continue;
    }
    tmp.clear();
    for (int i = 0; i < rev_word.size(); i++) {
        tmp.push_back(rev_word[i]);
        if (mp2[tmp])
            suf.push_back(tmp), tmp.clear();
        else
            continue;
    }
    int l = 0, r = word.size() - 1;
    for (int i = 0; i < pre.size(); i++) {
        for (int j = 0; j < pre[i].size(); j++) {
            l++;
        }
    }
    for (int i = 0; i < suf.size(); i++) {
        for (int j = 0; j < suf[i].size(); j++) {
            r--;
        }
    }
    string rel_word;
    for (int i = l; i <= r; i++)
        rel_word.push_back(word[i]);

    for (int i = pre.size() - 1; i >= 0; i--) {
        if (pre[i] == "anti")
            ans1 += "against ";
        else if (pre[i] == "post")
            ans1 += "after ";
        else if (pre[i] == "pre")
            ans1 += "before ";
        else if (pre[i] == "re")
            ans2 += " again";
        else
            ans1 += "not ";
    }

    for (int i = suf.size() - 1; i >= 0; i--) {
        if (suf[i] == "re")
            ans1 += "one who ", rel_word += "s";
        else if (suf[i] == "gni")
            ans1 += "to actively ";
        else if (suf[i] == "ezi")
            ans1 += "change into ";
        else if (suf[i] == "noit")
            ans1 += "the process of ", rel_word += "ing";
        else
            ans1 += "full of ";
    }

    cout << ans1 << rel_word << ans2 << endl;
}