#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIIP;
typedef pair<PII, char> PIC;
typedef pair<int, char> PICD;
const int INF = (int) 2e9;

int N;
llong arr[3001][5];
llong memo[3001][3];
llong dp(int id, int f)
{
    if(id == N - 1)
    {
        return f ? arr[id][1] : arr[id][0];
    }
    llong &ret = memo[id][f];
    if(ret != -1) return ret;
    ret = -(1LL<<60);
    if(f)
    {
        ret = max(ret, arr[id][1] + dp(id + 1, 1));
        ret = max(ret, arr[id][2] + dp(id + 1, 0));
    }
    else
    {
        ret = max(ret, arr[id][0] + dp(id + 1, 1));
        ret = max(ret, arr[id][1] + dp(id + 1, 0));
    }
    return ret;
}
int main()
{
    cin >> N;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < N; ++j)
            cin >> arr[j][i];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) << endl;
    return 0;
}
