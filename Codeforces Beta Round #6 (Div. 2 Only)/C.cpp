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

#define MOD 1000000009
#define mp make_pair
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;
const int INF = 1e9;

using namespace std;

int arr[100005];
int sum[100005];
int func(int l, int r)
{
    return sum[r] - sum[l - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N;
    cin >> N;
    for(int i = 0; i < N; ++i, sum[i] = sum[i - 1] + arr[i - 1])
        cin >> arr[i];
    for(int i = N; i >= 1; --i)
        if(func(1, i) <= func(1,N) - func(1, i) + arr[i - 1])
        {
            cout << i << ' ' << N - i;
            return 0;
        }
    return 0;
}