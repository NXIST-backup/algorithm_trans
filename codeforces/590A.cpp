#include "iostream"
using namespace std;
int main()
{
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        int sum=0;
        int x=0;
        int ans=0;
        for (int i = 1; i <= n;i++)
        {
            cin >> x;
            sum += x;
        }
        if (sum / n*n<sum)
            ans = sum / n + 1;
        else
            ans = sum / n;
        cout << ans << endl;
    }
}