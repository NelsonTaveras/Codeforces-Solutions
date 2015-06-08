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

int sumdigs(int n)
{
	int r = 0;
	while(n > 0)
	{
		r += n%10;
		n /= 10;
	}
	return r;
}

int dr(int N)
{
	while(1)
	{
		//cout << " - > " << N << endl;
		int s = sumdigs(N);
		if(s < 10)
			return s;
		else
			N = s;
	}
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int k, d;
    cin >> k >> d;
    if(d == 0)
    {
    	if(k > 1)
    		cout << "No solution" << endl;
    	else
    		cout << 0 << endl;
    	return 0;
    }
    if(k == 1)
    {
    	cout << d << endl;
    	return 0;
    }
    cout << 1;
    for(int i = 1; i < k - 1; ++i) cout << 0;
    if(k > 1)
    cout << d - 1 << endl;
    return 0;
}