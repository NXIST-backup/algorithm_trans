#include "iostream"
#include "map"
#include "vector"
#include <memory>
#include <vector>
using namespace std;

int t;
int n;
vector<int> a;
int main()
{
    cin >> t;

    while (t--) {
        a.clear();
        cin >> n;
        int sum = 0;
        int t = n;
        while(t)
        {
            a.push_back(t % 10);
            t /= 10;
        }
        while(n/10)
        {
            sum += 9;
            n /= 10;
        }
        int flag = 1;
        for (int i = a.size()-1; i > 0;i--)
        {
            if(a[i-1]>a[i])
            {
                flag = 1;
                break;
            }
            else if(a[i-1]<a[i])
            {
                flag = 0;
                break;
            }
            else
                continue;
        }

        if(flag)
            cout << sum + a.back() << endl;
        else
            cout << sum + a.back() - 1 << endl;
    }
}