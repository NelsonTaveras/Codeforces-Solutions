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
#define EPS 1e-9
int arr[10000 + 2];
int N, K;
double amount(double X, int K){
	return X - (1.0*(X*K)/100);
}
bool check(int N, double val){
	double got = 0.0;
	double need = 0.0;
	int cnt = 0;
	for(int i = 0; i < N; ++i){
		if(!(1.0*arr[i] <= val + EPS)){
			// excess..
			cnt++;
			got += (fabs(1.0*arr[i] - val));
		}
		else{
			// needs
			need += fabs(1.0*arr[i] - val);
		}
	}
	need -= amount(got, K);
	return need <= 0.0;
}
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for(int i = 0; i < N; ++i) 
		cin >> arr[i];
	double lo = 0.0, hi = 1000000.0;
	   for (int t = 1; t <= 70; ++t) {
		  double mid = (lo+hi)/2;
		  if(!check(N, mid))
			 hi = mid;
		  else
			 lo = mid;
	   }
	printf("%.10lf\n",(hi + lo) / 2);
	return 0;
}