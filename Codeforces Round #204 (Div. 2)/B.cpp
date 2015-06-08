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

int arr[(int) 1e5 + 5];
map<int, VI> M;
int main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    set<int> left;
    for(int i = 0; i < N; ++i) {
    	int id;
    	scanf("%d", &id);
    	arr[i] = id;
    	left.insert(id);
    	M[id].push_back(i + 1);
    }
    vector<PII> ANS;
    while(left.size() > 0){
    	int val = *left.begin();
    	if(M[val].size() == 1){
    		ANS.push_back(mp(val, 0));
    	}else{
    		bool pos = true;
    		int dif = M[val][1] - M[val][0];
    		for(int i = 2; i < M[val].size() && pos; ++i)
    			if(M[val][i] - M[val][i - 1] != dif){
    				pos = false;
    			}
    		if(pos)
    			ANS.push_back(mp(val, dif));
    	}
    	left.erase(val);
    }
    printf("%d\n", (int) ANS.size());
    for(int i = 0; i < ANS.size(); ++i)
    	printf("%d %d\n", ANS[i].first, ANS[i].second);
    return 0;
}