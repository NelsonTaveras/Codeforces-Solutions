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

using namespace std;

#define MAXN (int) 1050
#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;

int bus[MAXN];
int trolley[MAXN];

int main()
{
    //freopen("input.txt", "r", stdin);
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    	cin >> bus[i];
    for(int i = 0; i < m; ++i)
    	cin >> trolley[i];
    int costbus = 0;
    int costtrolley = 0;
    for(int i = 0; i < n; ++i)
    	costbus += min(bus[i] * c1, c2);
    costbus = min(costbus, c3);
    for(int i = 0; i < m; ++i)
    	costtrolley += min(trolley[i] * c1, c2);
    costtrolley = min(costtrolley, c3);
    cout << min(costbus + costtrolley, c4) << endl;
    return 0;
}