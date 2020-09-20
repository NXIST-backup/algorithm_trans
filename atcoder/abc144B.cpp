#include "iostream"
#include "vector"
#include <vector>
using namespace std;

const int N = 100;

int a[100];

int main()
{
    for (int i = 1; i <= 9;i++)
    {
        for (int j = 1; j <= 9;j++)
            a[i * j] = 1;
    }
    int n;
    cin >> n;
    if(a[n])
        cout << "Yes";
    else
        cout << "No";
}   