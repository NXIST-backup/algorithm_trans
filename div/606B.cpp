#include "iostream"
#include "map"
#include <map>
#include <vector>
#include "vector"
#include "algorithm"
#include "cstring"
#include "set"
using namespace std;

int t;
const int N = 2e5 + 50;
int a[N];
map<int, int> ying;
set<int> list;

int main()
{
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        list.clear();
        ying.clear();
        for (int i = 1; i <= n;i++)
        {
            int x;
            cin >> x;
            if(!(x%2)&&!ying[x])
            {
                list.insert(x);
                ying[x] = 1;
            }
        }
        for(int i)
        int ans = 0;
        cout << ans << endl;
    }
}