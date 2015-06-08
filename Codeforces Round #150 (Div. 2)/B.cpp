#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>

using namespace std;

typedef unsigned long long ullong;
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VII;

llong N;
set<int> V;
void gen(llong cur, llong x, llong y)
{
    if( cur > N || cur == 0 )
        return ;
    V.insert(cur);
    gen( (cur * 10) + x, x, y);
    gen( (cur * 10) + y, x, y);
}

int main()
{
    cin >> N;
    for(llong i = 0; i <= 9; ++i)
        for(llong j = 0; j <= 9; ++j)
            gen(i, i, j);
    cout << V.size();
    return 0;
}
