#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

int f[1020][1020];
int main(){
    f[0][0]=1;                                   
    for(int i=0;i<=1010;i++)
        for(int j=0;j<=1010;j++){
            if(i-1>=j)//上边一行的数要多于下边一行 才能往下边放                     
            	f[i][j]+=f[i-1][j]%2020;
            if(j)
            	f[i][j]+=f[i][j-1]%2020;
        }
        
    cout<<f[4][4]<<endl;   
    return 0;
}
