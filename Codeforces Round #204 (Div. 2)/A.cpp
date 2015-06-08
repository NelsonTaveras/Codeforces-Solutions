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

#define mp make_pair

#define MAXN (int) 1e5 + 5
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;

int main()
{
	//5555555555555555550
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    int f = 0;
    int z = 0;
    for(int i = 0; i < N; ++i){
    	int d;
    	cin >> d;
    	f += (d == 5);
    	z += (d == 0);
    }
    if(z < 1) 
    	cout << -1 << endl;
    else
    {
    	if(f >= 9){
    		int t = f / 9;
    		while(t)
    		{
		    	for(int i = 0; i < 9; ++i)
		    		cout << 5;
		    	t--;
    		}
	    }
    	for(int i = 0; i < z; ++i){
    		cout << 0;
    		if(f < 9) break;
    	}
    }
    return 0;
}