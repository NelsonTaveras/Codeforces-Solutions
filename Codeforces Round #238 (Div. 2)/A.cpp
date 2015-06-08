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
#include <ctime>
#include <cctype>
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const int INF = (llong) 1e9 + 50;
#define MOD (llong)  1000000007
const llong MAXN = 100050;

int arr[150];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    for(int i = N - 1; i >= 0; --i){
        int j = i;
        while(j + 1 < N && arr[j] > arr[j + 1]){
            int d = arr[j] - arr[j + 1];
            arr[j + 1] += d;
            arr[j] -= d;
            j++;
        }
    }
    for(int i = 0; i < N; ++i) cout << arr[i] << ' ';
    return 0;
}