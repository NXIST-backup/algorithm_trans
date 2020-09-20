#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> P;
vector<P> segs;
int main()
{
    int n;
    int x1, y1, x2, y2;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        segs.push_back({{x1, y1}, {x2, y2}});
    }
}