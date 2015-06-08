#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>

using namespace std;

#define mp make_pair
typedef pair<int, int> PI;
typedef pair<int, PI> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

int ret[101][100*101];
int arr[1000];
int N;
int mx = 0;
int go(int cur, int sum)
{
    if(cur >= N)
        return ( (sum & 1) ? sum : 0 );
    if(ret[cur][sum] != -1)
        return ret[cur][sum];
    int ret1 = 0;
        ret1 = max(ret1, go(cur + 1, sum + arr[cur]));
    int ret2 = 0;
        ret2 = max(ret2, go(cur + 1, sum));
    return ret[cur][sum] = max(ret1, ret2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    memset(ret, -1, sizeof(ret));
    cout << go(0, 0) << endl;
    return 0;
}
