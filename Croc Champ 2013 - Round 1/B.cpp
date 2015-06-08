#include <cmath>
#include <ctime>
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
#include <cctype>

using namespace std;
int D[200005];
int F[200005];
int main()
{
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		D[u]++;
		D[v]++;
	}
	for(int i = 0; i < N; ++i)
		F[D[i]]++;
	string ANS = "unknown topology";
	if(F[1] == 2)
		if(F[2] == N-2)
			ANS = "bus topology";
	if(F[2] == N)
		ANS = "ring topology";
	if(F[1] == N - 1)
		if(F[N-1] == 1)
			ANS = "star topology";
	cout << ANS;
	return 0;
}
