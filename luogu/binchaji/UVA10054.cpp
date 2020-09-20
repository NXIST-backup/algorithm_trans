#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int t, n;
int p[1005];
pair<bool, int> j[1005];

int find(int x)
{
    int t=p[x];
    if(t!=x)
        t=find(p[x]);
    return t;
}

int main()
{
    cin >> t;
    while(t--){

        cin >> n;

        for (int i = 1; i <= n;i++)
            p[i] = i;
        


    }
}