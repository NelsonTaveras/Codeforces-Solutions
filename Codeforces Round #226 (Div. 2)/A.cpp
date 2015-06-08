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
using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;
#define MOD (llong)  100999
#define in cin
#define out cout
const int MAXN = 5005;

int arr[(int) 1e5];
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; ++i){
      cin >> arr[i];
    }
    int ma = 0;
    for(int i = 0; i < n - 1; ++i){
      ma = max(ma, arr[i] - arr[i + 1] - c);
    }
    cout << ma << endl;
    return 0;
}