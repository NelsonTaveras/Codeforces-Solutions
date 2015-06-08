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
#define INF (int) 2e9

int arr[(int) 1e5 + 5];
int pos[(int) 1e5 + 5];
int vis[(int) 1e5 + 5];
int main() {
	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	bool swapped = false;
	for(int i = 0; i < N; ++i){
		if(arr[i] == i){
			continue;
		}
		else
		{
			if(swapped) continue;
			// arr[i] it's in position i
			if(pos[i] == arr[i]){
				int temp = arr[i];
				arr[i] = i;
				arr[pos[i]] = temp;
				swapped = true;
			}
		}
	}
	if(!swapped){
		for(int i = 0; i < N && !swapped; ++i){
			if(arr[i] == i){
				continue;
			}
			else
			{
				// find element in my position
				swap(arr[i], arr[pos[i]]);
				swapped = true;
			}
		}
	}	
	int cnt = 0;
	for(int i = 0; i < N; ++i)
		if(arr[i] == i)
			cnt++;
	cout << cnt << endl;
	return 0;
}