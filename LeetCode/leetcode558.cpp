#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

// Definition for a QuadTree node.
class Node
{
  public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
  public:
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        if (quadTree1->isLeaf || quadTree2->isLeaf) {
            if (quadTree1->isLeaf && quadTree1->val)
                return quadTree1;
            if (quadTree2->isLeaf && quadTree2->val)
                return quadTree2;
            if (quadTree1->isLeaf && !quadTree1->val)
                return quadTree2;
            if (quadTree2->isLeaf && !quadTree2->val)
                return quadTree1;
        }

        quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        bool flag1 = quadTree1->topLeft->val == quadTree1->topRight->val && quadTree1->topRight->val == quadTree1->bottomLeft->val && quadTree1->bottomLeft->val == quadTree1->bottomRight->val;
        bool flag2 = quadTree1->topLeft->isLeaf && quadTree1->topRight->isLeaf && quadTree1->bottomLeft->isLeaf && quadTree1->bottomRight->isLeaf;
        if (flag1 && flag2) {
            quadTree1->isLeaf = 1;
            quadTree1->val = quadTree1->topLeft->val;
            quadTree1->topLeft = NULL;
            quadTree1->topRight = NULL;
            quadTree1->bottomLeft = NULL;
            quadTree1->bottomRight = NULL;
        }

        return quadTree1;
    }
};
