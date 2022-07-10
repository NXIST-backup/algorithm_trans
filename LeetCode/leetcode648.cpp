#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

bool cmp(string a, string b)
{
    return a.size() > b.size();
}
class Solution
{
  public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        sentence.push_back(' ');
        vector<string> words;
        string word;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                words.push_back(word);
                word.clear();
                continue;
            }
            word.push_back(sentence[i]);
        }
        sort(dictionary.begin(), dictionary.end(), cmp);
        for (int i = 0; i < dictionary.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                string word = words[j];
                if (comp(word, dictionary[i]))
                    words[j] = dictionary[i];
            }
        }

        string ans;
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            ans += ' ';
        }
        return ans;
    }
    bool comp(string word, string s)
    {
        for (int i = 0; i < s.size(); i++)
            if (word[i] != s[i])
                return false;
        return true;
    }
};
int main()
{
    Solution s;
    vector<string> st = {"cat", "bat", "rat"};
    string content = "the cattle was rattled by the battery";
    cout << s.replaceWords(st, content) << endl;
}
