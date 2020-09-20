//博弈论问题


//公平组合游戏ICG
//若一个游戏满足：
//  1.由两名玩家交替行动
//  2.在游戏进程的任意时刻，可以执行的合法行动与轮到哪名玩家无关
//  3.不能行动的玩家判负
//  则称该游戏为一个公平组合游戏
//  nim属于公平组合游戏，但城建的棋类游戏，比如围棋，就不是公平组合游戏

//有向图游戏
//  给定一个有向无环图，图中有一个唯一的起点，在起点上放有一枚棋子。
//  两名玩家交替地把这枚棋子沿有向边进行移动，每次可以移动一步，无法
//  移动者判负，该游戏被称为有向图游戏。
//  任何一个公平组合游戏都可以转化为有向图游戏。具体方法是，把每个局面
//  看成图中的一个节点，并且从每个局面向沿着合法行动能够到达的下一个局面
//  连边

//Mex运算
//  设S表示一个非负整数集合。定义mex(S)为求出不属于集合S的最小非负整数
//  的运算，即：mex(S) = min{x}，x属于自然数，且x不属于S

//SG函数
//  在有向图游戏中，对于每个节点x，设从x出发共有k条有向边，分别到达节点
//  y1,y2,...,yk，定义SG(x)为x的后续节点y1,y2..yk的SG函数值构成的集合
//  再执行mes(S)运算的结果，即： SG(x) = mex{SG(y1),SG(y2)...SG(yk)}
//特别地，整个有向图游戏G的SG函数值被定义为有向图游戏起点s的SG函数值，即SG(G)=SG(s)

//有向图游戏的和
//  设G1,G2,..,Gm是m个有向图游戏。定义有向图游戏G，它的行动规则是任选某个有向图Gi
//  并在Gi上行动一步。G被称为有向图游戏G1,G2,...Gn
//  有向图游戏的和的SG函数值等于它包含的各个子游戏SG函数值的异或和，即：
//  SG(G) = SG(G1) ^ SG(G2) ..... ^ SG(Gm)

//定理
//  有向图游戏的某个局面必胜，当且仅当该局面对应节点的SG函数值大于0
//  有向图游戏的某个局面必败，当且仅当该局面对应节点的SG函数值等于0

//* nim chaifen




#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>
#include "unordered_set"
using namespace std;

const int N = 110;

int f[N];


int sg(int x)
{
    if(f[x]!=-1)
        return f[x];
    unordered_set<int> S;
    for (int i = 0; i < x;i++)
        for (int j = 0; j <= i;j++)
            S.insert(sg(i) ^ sg(j));
    //Mex操作
    for (int i = 0;;i++)
        if(!S.count(i))
            return f[x] = i;

}


int main()
{
    int n;
    cin >> n;

    int res = 0;
    memset(f, -1, sizeof f);
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if(res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}