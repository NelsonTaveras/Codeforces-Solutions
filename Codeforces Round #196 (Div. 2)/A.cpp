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
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int N, M;
    cin >> N >> M;
    VI arr(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int best = INF;
    for(int i = 0; i <= M - N; ++i){
        int mi = arr[i];
        int mx = arr[i + N - 1];
        best = min(best, mx - mi);
    }
    cout << best;
    return 0;
}