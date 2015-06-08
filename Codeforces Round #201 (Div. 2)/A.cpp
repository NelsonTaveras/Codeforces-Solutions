#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
using namespace std;

typedef long long llong;
typedef unsigned long long ullong;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define INF (int) 1e9

int main() {
	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	VI V(N);
	for(int i = 0; i < N; ++i) cin >> V[i];
	sort(V.rbegin(), V.rend());
	cout << V[0] << ' ';
	for(int i = V.size() - 2; i > 0; --i) cout << V[i] << ' ';
	cout << V.back();
	return 0;
}