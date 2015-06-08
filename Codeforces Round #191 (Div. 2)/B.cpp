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

int prime[(int) 1e7];

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    prime[0] = prime[1] = 1;
    for(llong i = 2; i <= 2000000; ++i)
    {
        for(llong j = i * i; j <= 2000000; j += i)
            prime[j] = 1;
    }
    VI V;
    for(int i = 2; i <= (int) 2000000 && N > 0; ++i)
        if(!prime[i])
        {
            cout << i << " ";
            N--;
        }
    return 0;
}
