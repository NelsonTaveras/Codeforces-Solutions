#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007
typedef long long llong;

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double SmallRHits = 1.0 * a / b;
    double ZanoesHits = 1.0 * c / d;
    double smallRFail = 1 - SmallRHits;
    double ZanoesFail = 1 - ZanoesHits;
    cout << SmallRHits / ( 1 - (smallRFail * ZanoesFail)) << endl;
    return 0;
}