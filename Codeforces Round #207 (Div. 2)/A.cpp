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

#define MAXN (int) 100005
#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;

int arr[105];

int main()
{
    //freopen("input.txt", "r", stdin);
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i)
    	cin >> arr[i];
    int x, y;
    cin >> x >> y;
    for(int i = 0; i < 1000; ++i)
    {
    	int good = 0;
    	int bad = 0;
    	for(int j = 1; j <= m; ++j)
    		if(j < i)
    			bad += arr[j - 1];
    		else
    			good += arr[j - 1];
    	if(good > y || bad > y) continue;
    	if(good < x || bad < x ) continue;
    	cout << i << endl;
    	return 0;
    }
    cout << 0 << endl;
    return 0;
}