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

int main()
{
    string A, B;
    cin >> A >> B;
    sort(B.rbegin(), B.rend());
    int curb = 0;
    for(int i = 0; i < (int) A.size() && curb < (int) B.size(); ++i)
    {
        if(A[i] < B[curb])
        {
            A[i] = B[curb];
            curb++;
        }
    }
    cout << A << endl;
    return 0;
}
