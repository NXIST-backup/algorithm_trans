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

int t;
int n, x, y;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;

        vector<int> a, b, c;
        if(n==2)
            cout << x << " " << y << endl;
        else if(y-x>n-2){
            int res = (y - x) % (n - 2);
            int t = (y - x + res) / (n - 2);
            int sum = x;
            a.push_back(x);
            n -= 2;
            while (sum+t<y&&n--) {
                sum += t;
                a.push_back(sum);
            }
            sum = x;
            while (sum > 0&&n--) {
                sum -= t;
                b.push_back(sum);
            }
            sum = y;
            c.push_back(y);
            while (n-->0) {
                sum += t;
                c.push_back(sum);
            }
            for(auto item:b)
                cout << item << " ";
            for(auto item:a)
                cout << item << " ";
            for(auto item:c)
                cout << item << " ";
            cout << endl;
        }
        else{
            n -= 2;
            while (n--) {
                int t = n - y + x;
                int item = max(1, x - t);
                while (t--&&item<=x) {
                    cout << item++ << " ";
                }
                for (int i = x + 1; i < y;i++) {
                    cout << i << " ";
                }
                item = y;
                while (t--) {
                    cout << item << " ";
                }
                cout << endl;
            }
        }
    }
}