#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <set>
#include <cstring>
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

llong arr[(int) 1e5];

int main()
{
	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> arr[i];
	llong bill25 = 0;
	llong bill50 = 0;
	llong bill100 = 0;
	for(int i = 0; i < N; ++i)
	{
		if(arr[i] == 25)
			bill25 += 1;
		else
		{
			bool changed = false;
			if(arr[i] == 50)
			{
				if(bill25 > 0)
				{
					bill25--;
					bill50++;
					changed = true;
				}
			}
			else if(arr[i] == 100)
			{
				if(bill50 > 0 && bill25 > 0)
				{
					bill25--;
					bill50--;
					bill100++;
					changed = true;
				}
				else if(bill25 >= 3)
				{
					bill25 -= 3;
					bill100++;
					changed = true;
				}
			}
			if(!changed)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
}