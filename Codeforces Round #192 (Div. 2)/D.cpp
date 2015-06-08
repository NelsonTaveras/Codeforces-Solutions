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
typedef pair<int, PI> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
int dist[1003][1003];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int main()
{
	int R, C;
	cin >> R >> C;
	vector<string> V(R);
	for(int i = 0; i < R; ++i)
		cin >> V[i];
	int exitr, exitc;
	int curr, curc;
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			if(V[i][j] == 'E'){
				exitr = i;
				exitc = j;
			}
			else if(V[i][j] == 'S'){
				curr = i;
				curc = j;
			}
	memset(dist, 0x3f, sizeof(dist));
	dist[exitr][exitc] = 0;
	queue<PI> Q;
	Q.push(mp(exitr, exitc));
	while(!Q.empty())
	{
		PI P = Q.front();
		Q.pop();
		int curx = P.first;
		int cury = P.second;
		int d = dist[curx][cury];
		for(int i = 0; i < 4; ++i)
		{
			int nx = curx + dr[i];
			int ny = cury + dc[i];
			if(nx >= 0 && ny >= 0 && nx < R && ny < C)
				if(V[nx][ny] != 'T')
					if(dist[nx][ny] > d + 1)
					{
						dist[nx][ny] = d + 1;
						Q.push(mp(nx, ny));
					}
		}
	}
	int D = dist[curr][curc];
	int ret = 0;
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			if(V[i][j] >= '0' && V[i][j] <= '9')
				if(dist[i][j] <= D)
					ret += (V[i][j] - '0');
	cout << ret << endl;
    return 0;
}
