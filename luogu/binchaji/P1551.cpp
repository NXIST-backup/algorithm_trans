#include "iostream"
using namespace std;

int n, m, p;
int fa[5005];

int find(int x)
{
    if(fa[x]!=x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

int main()
{
    cin >> n >> m >> p;

    for (int i = 1; i <= n;i++)
        fa[i] = i;
    
    while(m--){
        int m1, m2;
        cin >> m1 >> m2;

        int fa1 = find(m1), fa2 = find(m2);

        fa[fa1] = fa2;
    }

    while(p--){

        int p1, p2;
        cin >> p1 >> p2;
        int fa1 = find(p1), fa2 = find(p2);
        if(fa1!=fa2)
            cout << "No" << endl;

        else
            cout << "Yes" << endl;
    }

}