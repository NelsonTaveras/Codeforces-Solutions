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
const int INF = (int) 1e9;

int type[MAXN];
int outd[MAXN];

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	VVI adj(N);
	for(int i = 0; i < N; ++i) cin >> type[i];
	for(int i = 0; i < N; ++i){
		int id;
		cin >> id;
		if(id != 0){
			outd[id - 1]++;
			adj[i].push_back(id - 1);
		}
	}
	VI ANS;
	for(int i = 0; i < N; ++i){
		if(type[i]){
			int cur = i;
			VI res;
			while(1){
				if(outd[cur] > 1){
					break;
				}
				res.push_back(cur);
				if(adj[cur].size() == 0) break;
				cur = adj[cur][0];
			}
			if(res.size() > ANS.size())
				ANS = res;
		}
	}
	cout << ANS.size() << endl;
	reverse(ANS.begin(), ANS.end());
	for(int i = 0; i < ANS.size(); ++i) cout << ANS[i] + 1 << " ";
	return 0;
}