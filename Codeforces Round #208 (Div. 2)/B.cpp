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

int main()
{
	int N;
	cin >> N;
	vector<string> V(N);
	string GOOD = "<3";
	for(int i = 0; i < N; ++i){
		cin >> V[i];
		GOOD += V[i];
		GOOD += "<3";
	}
	//cout << GOOD << endl << modify(GOOD) << endl;
	string S;
	cin >> S;
	int idx = 0;
	//cout << GOOD << endl;
	for(int i = 0; i < S.size(); ++i)
	{
		if(idx >= GOOD.size())
		{
			break;
		}
		if(S[i] >= 'a' && S[i] <= 'z'){
			//cout << S[i] << " " << GOOD[idx] << endl;
			if(S[i] == GOOD[idx]) idx++;
		}
		else{
			if(S[i] == GOOD[idx]) idx++;
		}
	}
	if(idx < GOOD.size()) cout << "no";
	else cout << "yes";
    return 0;
}
