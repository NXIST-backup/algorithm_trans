#include "iostream"
#include "cmath"
using namespace std;

int n;
const int N = 1e4 + 10;

int main()
{
    cin >> n;
    while (n--) {

        int x, y;
        
        cin >> x >> y;

        int ans[N];
        int cnt = y % x;
        for (int i = 0; i < x;i++)
            ans[i] = y / x;
        int j = 0;
        while (cnt--) {
            ans[j++]++;
        }
        int sum = 0;
        for (int i = 0; i < x;i++)
            sum += pow(ans[i], 2);

        cout << sum << endl;
    }
}