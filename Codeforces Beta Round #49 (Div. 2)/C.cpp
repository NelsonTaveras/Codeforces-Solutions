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
    //freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    cout << 1 << " ";
    int last = 1;
    set<int> saw;
    saw.insert(1);
    for(int i = N - 1; i > 0; --i)
    {
    	int x1 = last - i;
    	int x2 = last + i;
    	if(x1 <= 0 || x1 > N || saw.count(x1)){
    		cout << x2 << " ";
    		last = x2;
    	}
    	else{
    		cout << x1 << " ";
    		last = x1;
    	}
    	saw.insert(last);
    }
    return 0;
}
