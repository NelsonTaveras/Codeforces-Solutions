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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);

    llong x, y, a, b;
    cin >> x >> y >> a >> b;
    llong l = x * (y / __gcd(x, y));
    cout << (b / l) - (a - 1) / l;

    return 0;
}