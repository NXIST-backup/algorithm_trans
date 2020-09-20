#include "iostream"
#include "cstring"
#include "algorithm"
#include "queue"

using namespace std;

int t;

const int N = 105;

string a;
int cnt = 0;
int main()
{
    cin >> t;
    while (t--) {
        cin >> a;
        int flag1 = 0;
        int flag2 = 0;
        cnt = 0;
        int l = 0, r = a.size()-1;

        while (l<=r) {
            
            if(flag1&&flag2)
            {
                if(a[l]=='0')
                {
                    cnt++;
                    l++;
                }
                else
                    l++;
            }
            else {               
                if(a[l]=='1')
                    flag1 = 1;
                else
                    l++;
                if(a[r]=='1')
                    flag2 = 1;
                else
                    r--;
            }
        }
        cout << cnt << endl;
    }
}