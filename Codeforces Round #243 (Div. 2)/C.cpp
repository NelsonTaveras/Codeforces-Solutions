#include <cmath>
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
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);

int sum[255];
int arr[255];
int get(int l, int r){
    return sum[r] - (l > 0 ? sum[l - 1] : 0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n, K;
    cin >> n >> K;
    int ma = -(1LL<<30);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        ma = max(ma, arr[i]);
    }
    sum[0] = 0;
    for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + arr[i - 1];
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            int sum = get(i, j);
            priority_queue<int, vector<int>, greater<int> > in;
            priority_queue<int> out;
            for(int k = i - 1; k < j; ++k) in.push(arr[k]);
            for(int k = i - 2; k >= 0; --k) out.push(arr[k]);
            for(int k = j; k < n; ++k) out.push(arr[k]);
            int k = K;
            ma = max(ma, sum);
            while(k > 0 && !in.empty() && !out.empty()){
                int x = in.top();
                in.pop();
                int x2 = out.top();
                out.pop();
                sum -= x;
                sum += x2;
                ma = max(ma, sum);
                --k;
            }
        }
    }
    cout << ma << endl;
    return 0;
}