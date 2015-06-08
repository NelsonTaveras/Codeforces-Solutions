#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <set>
#include <cstring>
#include <ctime>
#include <map>

using namespace std;

#define INF (int) 2e9
#define mp make_pair

typedef unsigned long long ullong;
typedef long long llong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;

int arr[15];
vector<string> ANS;
int tot;
int memo[(int) 1e6 + 5];
int act[(int) 1e6 + 5];
int mi = 100000000;
int dp(int left)
{
	if(left < mi) return 0;
	if(memo[left] != -1) return memo[left];
	int l = 0;
	for(int i = 0; i < 9; ++i)
		if(left >= arr[i]){
			int w = 1 + dp(left - arr[i]);
			if(w > l)
			{
				l = w;
				act[left] = i;
			}
			else if(w == l)
			{
				act[left] = max(act[left], i);
			}
		}
	return memo[left] = l;
}
void doit(int left)
{
	while(1){
		if(left < mi) break;
		int choice = act[left];
		int cost = arr[choice];
		left -= cost;
		cout << choice + 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> tot;
	for(int i = 0; i < 9; ++i){
		cin >> arr[i];
		mi = min(mi, arr[i]);
	}
	memset(memo, -1, sizeof(memo));
	if(dp(tot) == 0)
		cout << -1 << endl;
	else
	{
		doit(tot);
	}
}