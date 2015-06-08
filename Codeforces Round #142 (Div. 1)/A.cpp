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

int C[101][10001];

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
    	for(int j = 0; j < M; ++j)
    		C[i][j] = INF;
    for(int i = 0; i < N; ++i)
    {
    	string S;
    	cin >> S;
    	int l = -1;
    	int ll = INF;
    	for(int j = 0; j < M; ++j)
    	{
    		if(S[j] == '1')
    			l = j, C[i][j] = 0;
    		else
    		{
    			if(l != -1)
    				C[i][j] = min(C[i][j], j - l);
    		}
    		if(l != -1) ll = min(ll, l);
    	}
    	l = -1;
    	int rr = -1;
    	for(int j = M - 1; j >= 0; --j)
    	{
    		if(S[j] == '1')
    			l = j, C[i][j] = 0;
    		else
    		{
    			if(l != -1)
    				C[i][j] = min(C[i][j], l - j);
    		}
    		if(l != -1) rr = max(rr, l);
    	}
    	if(rr != -1)
    	{
    		for(int j = 0; j < M; ++j)
    			C[i][j] = min(C[i][j], M - rr + j);
    	}
    	if(ll != -1)
    	{
    		for(int j = M - 1; j >= 0; --j)
    			C[i][j] = min(C[i][j], ll + M - j);
    	}
    }
    llong ret = INF;
    for(int i = 0; i < M; ++i)
    {
    	llong cost = 0;
    	for(int j = 0; j < N; ++j)
    		cost += C[j][i];
    	ret = min(ret, cost);
    }
    cout << (ret == INF ? -1 : ret) << endl;
    return 0;
}