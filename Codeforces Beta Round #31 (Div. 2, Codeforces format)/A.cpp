#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cctype>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
int arr[110];
int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> arr[i];
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			for(int k = 0; k < N; ++k)
				if( i != j && j != k )
				{
					if(arr[i] == arr[j] + arr[k])
					{
						cout << i + 1 << ' ' << j + 1 << ' ' << k + 1;
						return 0;
					}
				}
	cout << -1;
    return 0;
}
