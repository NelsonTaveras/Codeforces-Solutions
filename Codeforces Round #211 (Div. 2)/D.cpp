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
const int MAXN = 1000010;

llong B[MAXN];
llong P[MAXN];
bool check(llong mid, llong budget)
{
    int cur = mid - 1;
    llong need = 0;
    for(int i = 0; i < mid; ++i)
        need += max(0LL, P[cur--] - B[i]);
    return need <= budget;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int N, M, budget;
    cin >> N >> M >> budget;
    for(int i = 0; i < N; ++i) cin >> B[i];
    for(int i = 0; i < M; ++i) cin >> P[i];
    sort(P, P+M);
    sort(B, B+N);
    reverse(B, B+N);
    llong lo = 0, hi = min(N, M);
    while(lo < hi){
        llong mid = lo + (hi - lo + 1) / 2;
        if(!check(mid, budget))
            hi = mid - 1;
        else
            lo = mid;
    }
    llong sum = 0;
    for(int i = lo - 1; i >= 0; --i) sum += P[i];
    cout << lo << ' ' << max(0LL, sum - budget) << endl;
    return 0;
}
