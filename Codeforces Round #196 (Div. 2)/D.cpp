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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long llong;
const int INF = 1e9;
using namespace std;
int I[100005];
int DIST[100005];
int DIST2[100005];
int V[100005];
VVI adj;
void dfs(int u, int d)
{
	V[u] = 1;
	DIST[u] = d;
	for(int i = 0; i < adj[u].size(); ++i)
	{
		int v = adj[u][i];
		if(V[v] == 0)
		{
			V[v] = 1;
			dfs(v, d + 1);
		}
	}
}
void dfs2(int u, int d)
{
	V[u] = 1;
	DIST2[u] = d;
	for(int i = 0; i < adj[u].size(); ++i)
	{
		int v = adj[u][i];
		if(V[v] == 0)
		{
			V[v] = 1;
			dfs2(v, d + 1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int N, M, D;
	cin >> N >> M >> D;
	for(int i = 0; i < M; ++i)
	{
		int id;
		cin >> id;
		I[id - 1] = 1;
	}
	adj = VVI(N);
	for(int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0);
	int MX = -1;
	int id = -1;
	for(int i = 0; i < N; ++i)
		if(I[i] && DIST[i] > MX)
		{
			MX = DIST[i];
			id = i;
		}
	memset(DIST, 0, sizeof(DIST));
	memset(V, 0, sizeof(V));
	dfs(id, 0);
	int NMX = -1;
	int NID = -1;
	for(int i = 0; i < N; ++i)
		if(I[i] && DIST[i] > NMX)
		{
			NMX = DIST[i];
			NID = i;
		}
	memset(V, 0, sizeof(V));	
	dfs2(NID, 0);
	int ret = 0;
	for(int i = 0; i < N; ++i)
		if(DIST[i] <= D && DIST2[i] <= D)
			ret++;
	cout << ret << endl;
	return 0;
}