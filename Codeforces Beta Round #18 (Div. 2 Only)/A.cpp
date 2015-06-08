#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long ullong;
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef pair<int, PI> PIP;

llong ax, ay, bx, by, cx, cy;
bool check(llong ax,llong ay,llong bx,llong by,llong cx, llong cy)
{
	llong a = ((bx-ax) * (bx-ax)) + ((by-ay) * (by-ay));
	llong b = ((cx-bx) * (cx-bx)) + ((cy-by) * (cy-by));
	llong c = ((cx-ax) * (cx-ax)) + ((cy-ay) * (cy-ay));

	if(a==0 || b==0 || c==0)return false;
	if(a>b)swap(a,b);
	if(a>c)swap(a,c);
	if(b>c)swap(b,c);
	return a + b == c;
}
int main()
{
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    int ret = 0;
    ret += check(ax, ay, bx, by, cx, cy);
    if(ret)
    {
    	cout << "RIGHT";
    	return 0;
    }
    else
    {
    	ret += check(ax + 1, ay, bx, by, cx, cy);
    	ret += check(ax, ay + 1, bx, by, cx, cy);
    	ret += check(ax - 1, ay, bx, by, cx, cy);
    	ret += check(ax, ay - 1, bx, by, cx, cy);
    	ret += check(ax, ay, bx + 1, by, cx, cy);
    	ret += check(ax, ay, bx - 1, by, cx, cy);
    	ret += check(ax, ay, bx, by + 1, cx, cy);
    	ret += check(ax, ay, bx, by - 1, cx, cy);
    	ret += check(ax, ay, bx, by, cx + 1, cy);
    	ret += check(ax, ay, bx, by, cx - 1, cy);
    	ret += check(ax, ay, bx, by, cx, cy + 1);
    	ret += check(ax, ay, bx, by, cx, cy - 1);

		if(ret)
		{
			cout << "ALMOST";
			return 0;
		}
    }
    cout << "NEITHER";
    return 0;
}
