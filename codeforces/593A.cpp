#include "iostream"
using namespace std;
int t;
int a, b, c;
int main()
{
    cin >> t;
    while(t--){
        int sum1 = 0;
        int sum2 = 0;
        cin >> a >> b >> c;
        int a1 = a, b1 = b, c1 = c;
        while(a&&b>=2){
            a--;
            b -= 2;
            sum1 += 3;
        }
        while(b&&c>=2){
            b--;
            c -= 2;
            sum1 += 3;
        }
        a = a1, b = b1, c = c1;
        while(b&&c>=2){
            b--;
            c -= 2;
            sum2 += 3;
        }
        while(a&&b>=2){
            a--;
            b -= 2;
            sum2 += 3;
        }
        sum1 = max(sum1, sum2);
        cout << sum1 << endl;
    }
}