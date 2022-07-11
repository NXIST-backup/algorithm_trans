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

class MagicDictionary
{
  public:
    unordered_set<string> st;
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        st.clear();
        for (int i = 0; i < dictionary.size(); i++)
            st.insert(dictionary[i]);
    }

    bool search(string searchWord)
    {
        for (int i = 0; i < searchWord.size(); i++)
            for (int j = 'a'; j <= 'z'; j++) {
                if (j == searchWord[i])
                    continue;
                char tmp = searchWord[i];
                searchWord[i] = j;
                if (st.count(searchWord))
                    return true;
                searchWord[i] = tmp;
            }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
