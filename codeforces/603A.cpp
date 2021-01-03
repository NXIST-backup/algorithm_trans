#include "iostream"

using namespace std;

int t;
int r, g, b;


int main()
{
    cin >> t;
    while (t--) {
        cin >> r >> g >> b;
        for (int i = 0; i < 3;i++)
        {
            if (b > g)
            {
                swap(g, b);
            }
            if(g>r)
            {
                swap(r, g);
            }
            if(b>r)
            {
                swap(r, b);
            }
        }
        int sum = 0;
        int temp = g - b;
        r -= temp;
        g -= temp;
        sum += temp;
        if(r==g&&g==b)
        {
            cout << sum + (r + g + b) / 2 << endl;
            continue;
        }
        if(r>=g+b)
            cout << sum + g+b << endl;
        else if(g%2)
            cout << sum + g * 3 / 2 + (r - g+1) / 2 << endl;
        else
            cout << sum + g * 3 / 2 + (r - g) / 2 << endl;

    }
}