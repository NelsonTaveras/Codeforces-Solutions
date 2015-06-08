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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;
const int INF = 1e9;

using namespace std;

VI V;
int solve(int N)
{
    VI I(N+1);
    for(int i = 0; i <= N; ++i)
        I[i] = INF;
    I[0] = -INF;
    int ANS = 0;
    for(int i = 0; i < N; ++i)
    {
        VI::iterator low = lower_bound(I.begin(), I.end(), V[i]);
        int pos = low - I.begin();
        I[pos] = V[i];
        ANS = max(ANS, pos);
    }
    return ANS;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    V = VI(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];
    cout << solve(N);
    return 0;
}