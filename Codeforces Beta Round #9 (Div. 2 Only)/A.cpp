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

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;



int main()
{
	ios_base::sync_with_stdio(false);
	int A, B;
	cin >> A >> B;
	int num = 6 - max(A, B) + 1;
	int dem = 6;
	int gcd = __gcd(num, dem);
	num /= gcd;
	dem /= gcd;
	cout << num << "/" << dem;
	return 0;
}
