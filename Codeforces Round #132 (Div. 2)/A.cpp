#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int freq[1000005];
int a[10000];
int b[10000];

int main()
{
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i)
        cin >> a[i];

    int M;
    cin >> M;

    for(int i = 0; i < M; ++i)
        cin >> b[i];

    int mx = -1;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            if( b[j] % a[i] == 0 )
            {
                mx = max(mx, b[j] / a[i]);
                freq[ b[j] / a[i] ]++;
            }

    cout << freq[mx] << endl;
    return 0;
}
