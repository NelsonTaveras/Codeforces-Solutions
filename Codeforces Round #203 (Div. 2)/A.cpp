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
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 1e9;

int ac[500];
int wa[500];

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; ++i) cin >> ac[i];
	for(int i = 0; i < M; ++i) cin >> wa[i];
	for(int i = 1; i <= 100; ++i){
		bool pos = true;
		for(int j = 0; j < N && pos; ++j)
			if(ac[j] > i)
				pos = false;
		for(int j = 0; j < M && pos; ++j)
			if(wa[j] <= i)
				pos = false;
		int cnt = 0;
		for(int j = 0; j < N && pos; ++j)
			if(2*ac[j] <= i)
				cnt++;
		if(pos && cnt > 0){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1;
	return 0;
}