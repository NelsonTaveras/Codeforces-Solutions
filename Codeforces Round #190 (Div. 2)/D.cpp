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
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const int INF = (int) 1e9;

VI cielATK;
VI jiroATK;
VI jiroDEF;

int killAll(){
	VI tmpjiroATK = jiroATK;
	VI tmpjiroDEF = jiroDEF;
	VI tmpcielATK = cielATK;
	VI leftATK;
	sort(tmpjiroATK.begin(), tmpjiroATK.end());
	sort(tmpjiroDEF.begin(), tmpjiroDEF.end());
	sort(tmpcielATK.begin(), tmpcielATK.end());
	while(tmpjiroDEF.size() > 0){
		int need = tmpjiroDEF.back();
		VI::iterator low = lower_bound(tmpcielATK.begin(), tmpcielATK.end(), need);
		if(low == tmpcielATK.end()) return -INF;
		int pos = low - tmpcielATK.begin();
		if(tmpcielATK[pos] > need)
			tmpjiroDEF.pop_back();
		else
			leftATK.push_back(tmpcielATK[pos]);
		tmpcielATK.erase(tmpcielATK.begin() + pos);
	}
 	for(int i = 0; i < leftATK.size(); ++i) tmpcielATK.push_back(leftATK[i]);
	sort(tmpcielATK.rbegin(), tmpcielATK.rend());
	int sum = 0;
	int idxATK = 0;
	
	while(tmpjiroATK.size() > 0 && idxATK < tmpcielATK.size()){
		int got = tmpcielATK[idxATK];
		int need = tmpjiroATK.back();
		if(need > got) break;
		sum += (got - need);
		idxATK++;
		tmpjiroATK.pop_back();
	}
	if(tmpjiroATK.size() > 0) return -INF;
	for(int i = idxATK; i < tmpcielATK.size(); ++i) sum += tmpcielATK[i];
	return sum;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		string t;
		int s;
		cin >> t >> s;
		if(t == "ATK") 
			jiroATK.push_back(s);
		else
			jiroDEF.push_back(s);
	}
	for(int i = 0; i < M; ++i){
		int s;
		cin >> s;
		cielATK.push_back(s);
	}
	int ret = killAll();
	int ret2 = 0;
	sort(cielATK.rbegin(), cielATK.rend());
	sort(jiroATK.begin(), jiroATK.end());
	for(int i = 0; i < min(cielATK.size(), jiroATK.size()); ++i){
		if(jiroATK[i] > cielATK[i]) break;
		ret2 += cielATK[i] - jiroATK[i];
	}
	cout << max(ret, ret2) << endl;
	return 0;
}