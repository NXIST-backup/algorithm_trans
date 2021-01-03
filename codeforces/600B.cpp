#include "iostream"
#include "vector"
#include "stack"
#include "map"
using namespace std;

int n;
const int N = 100050;
int a[N],b2[N];
vector<int> c;
stack<int> b;
int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++)
        cin >> a[i];

    b.push(a[1]);
    for (int i = 2; i <= n;i++)
    {
        if(b.top()==a[i])
            b.pop();
        if(b.empty())
            c.push_back(i);
        
    }
}