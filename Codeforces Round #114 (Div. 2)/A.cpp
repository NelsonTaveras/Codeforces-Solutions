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

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;

    int _need = ( (Y * N) / 100 +  ( (Y * N) % 100 != 0) );
    cout << max(0, _need - X);

    return 0;
}
