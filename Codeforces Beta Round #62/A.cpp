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

vector<int> V(4);
int A, B;
int cnt(){
	int ans = 0;
	for(int i = A; i <= B; ++i)
	{
		vector<int> temp = V;
		int cnt = 0;
		do{
			int res = i % temp[0];
				res %= temp[1];
				res %= temp[2];
				res %= temp[3];
				if(res == i) cnt++;
		}while(next_permutation(temp.begin(), temp.end()));

		if(cnt >= 7) ans++;
	}
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	for(int i = 0; i < 4; ++i)
		cin >> V[i];
	sort(V.begin(), V.end());
	cin >> A >> B;
	cout << cnt() << endl;
	return 0;
}