#include "iostream"
#include "cstring"
using namespace std;

int t;

int x, y, a, b;



int main()
{
    cin >> t;
    while (t--) {

        cin >> x >> y >> a >> b;

        int ans = (y - x) / (a + b);
        int flag = (y - x) % (a + b);
        if(!flag)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}