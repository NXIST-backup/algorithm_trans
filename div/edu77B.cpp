#include "iostream"

using namespace std;

int t;



int main()
{
    cin >> t;
    while (t--) {

        int a, b;
        cin >> a >> b;
        if(!a&&!b)
        {
            cout << "Yes" << endl;
        }
        else if((a+b)%3||a+b<3)
            cout << "No" << endl;
        else
        {
            int sum = (a + b) / 3;
            int r = sum * 2, l = sum * 1;
            if (a <= r && a >= l&&b<=r&&b>=l)
                cout << "Yes" << endl;

            else
                cout << "No" << endl;
        }
    }
}