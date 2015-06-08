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
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	map<string, int> score, score2;
	vector<pair<string, int> > V;
	int mx = -INF;
	for(int i = 0; i < N; ++i){
		string s;
		int cnt;
		cin >> s >> cnt;
		score[s] += cnt;
		V.push_back(mp(s, cnt));
	}
	for(map<string, int>::iterator it = score.begin(); it != score.end(); ++it)
		mx = max(mx, it->second);
	int cnt = 0;
	for(map<string, int>::iterator it = score.begin(); it != score.end(); ++it)
		if(it->second == mx)
			cnt++;
	if(cnt == 1){
		for(map<string, int>::iterator it = score.begin(); it != score.end(); ++it)
			if(it->second == mx){
				cout << it->first << endl;
				return 0;
			}
	}
	for(int i = 0; i < V.size(); ++i){
		string s = V[i].first;
		score2[s] += V[i].second;
		if(score2[s] >= mx && score[s] == mx){
			cout << s << endl;
			return 0;
		}
	}
	return 0;
}