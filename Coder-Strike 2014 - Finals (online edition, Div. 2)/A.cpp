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

int ar[150];
int br[150];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < a; ++i){
    	int x;
    	cin >> x;
    	ar[x] = 1;
    }
    for(int i = 0; i < b; ++i){
    	int x;
    	cin >> x;
    	br[x] = 1;
    }
    for(int i = 1; i <= n; ++i){
    	if(ar[i] > 0)
			cout << 1 << ' ';
		else
			cout << 2 << ' ';
    }
    return 0;
}