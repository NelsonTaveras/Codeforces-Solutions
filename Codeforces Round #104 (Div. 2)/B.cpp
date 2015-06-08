#include <cmath>
#include <ctime>
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
#include <cctype>

using namespace std;

#define mp make_pair
typedef pair<int, int> PI;
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
int INF = 1e9;

int mask(int N)
{
	string S;
	while(N > 0)
	{
		int d = N % 10;
		if( d == 4 || d == 7 )
			S += ( d + '0' );
		N /= 10;
	}
	reverse(S.begin(), S.end());
	istringstream is(S);
	int msk;
	is >> msk;
	return msk;
}

int main()
{
	int A, B;
	cin >> A >> B;
	A++;
	while(mask(A) != B)
		A++;
	cout << A;
	return 0;
}
