#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long ullong;
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef pair<int, PI> PIP;

llong cross_product( llong ax, llong ay, llong bx, llong by, llong cx, llong cy )
{
       return (bx-ax)*(cy-ay) - (cx-ax)*(by-ay);
}

int main()
{
    llong ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    llong cp = cross_product(ax, ay, bx, by, cx, cy);
    if( cp < 0 )
        cout << "RIGHT";
    else if( cp == 0 )
        cout << "TOWARDS";
    else
        cout << "LEFT";
    return 0;
}

