#include <cmath>
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
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);

int arr[12345];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    int got = 0;
    for(int i = 0; i < n - 1; ++i)
        got += arr[i];
    cout << ((got > s ? "NO" : "YES")) << endl;
    return 0;
}