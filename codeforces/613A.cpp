#include "iostream"
using namespace std;

int n;


int main()
{
    cin >> n;

    int L=0, R=0;

    for (int i = 0; i < n;i++)
    {
        char s;
        cin >> s;
        if(s=='L')
            L++;
        else
            R++;
    }
    cout << L + R + 1 << endl;

}