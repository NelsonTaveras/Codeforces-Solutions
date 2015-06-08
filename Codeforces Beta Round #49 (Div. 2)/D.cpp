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

int a[301];
int b[301];

int main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> a[i];
    for(int i = 0; i < N; ++i) cin >> b[i];
    vector<PII> ANS;
    for(int i = 0; i < N; ++i)
    	if(b[i] != a[i])
    	{
    		int idx = -1;
    		for(int j = i + 1; j < N && idx == -1; ++j)
    			if(b[j] == a[i])
    				idx = j;
    		while(idx != i){
    			ANS.push_back(PII(idx, idx + 1));
    			swap(b[idx], b[idx - 1]);
    			idx--;
    		}
    	}
    cout << ANS.size() << endl;
    for(int i = 0; i < ANS.size(); ++i)
    	cout << ANS[i].first << " " << ANS[i].second << endl;
    return 0;
}
