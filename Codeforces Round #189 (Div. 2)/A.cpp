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

#define mp make_pair
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;

set<llong> S;
void gen(llong cur)
{
    if( cur > 1e9 )
        return ;
    S.insert(cur);
    gen(cur * 10 + 1);
    gen(((cur * 10 + 1)*10)+4);
    gen(((((cur * 10 + 1)*10)+4)*10)+4);
}

int main()
{
    llong n;
    cin >> n;

    gen(1);
    gen(14);
    gen(144);
    cout << (S.count(n) ? "YES" : "NO");
    return 0;
}
