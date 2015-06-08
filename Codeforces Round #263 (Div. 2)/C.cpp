#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <ctime>
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
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e6 + 5;
const int MOD = 1000000007;

using namespace std;

int arr[maxn];

int main() {

    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    if(N == 1){
        cout << arr[0] << endl;
        return 0;
    }
    sort(arr, arr + N);
    reverse(arr, arr + N);
    llong sum = 0;
    for(int i = 0; i < N; ++i) sum += arr[i];
    llong ans = sum;
    llong gone = 0;
    for(int i = 0; i < N - 1; ++i){
        ans += (sum - gone);
        gone += arr[N - i - 1];
    }
    cout << ans << endl;
    return 0;
}
