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
#include <ctime>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 1e9;

int X[(int) 1e5 + 10];
int Y[(int) 1e5 + 10];
vector<PII> V;
vector<pair<int, pair<int, char> > > ANS;
struct Point{
	int x;
	int y;
	int dist;
	bool operator <(Point p)const{
		return dist < p.dist;
	}
};
int N;
void solve()
{
	for(int i = 0; i < N; ++i){
		int x = X[i];
		int y = Y[i];

		// Get to the x
		if(x != 0)
		{
			pair<int, pair<int, char> > p;
			p.first = 1;
			p.second.first = abs(x);
			if(x < 0)
				p.second.second = 'L';
			else
				p.second.second = 'R';
			ANS.push_back(p);
		}
		if(y != 0)
		{
			pair<int, pair<int, char> > p;
			p.first = 1;
			p.second.first = abs(y);
			if(y < 0)
				p.second.second = 'D';
			else
				p.second.second = 'U';
			ANS.push_back(p);
		}
		// Drop the bomb
		ANS.push_back(mp(2, mp(2, '2')));
		if(x != 0)
		{
			pair<int, pair<int, char> > p;
			p.first = 1;
			p.second.first = abs(x);
			if(x < 0)
				p.second.second = 'R';
			else
				p.second.second = 'L';
			ANS.push_back(p);
		}
		if(y != 0)
		{
			pair<int, pair<int, char> > p;
			p.first = 1;
			p.second.first = abs(y);
			if(y < 0)
				p.second.second = 'U';
			else
				p.second.second = 'D';
			ANS.push_back(p);
		}
		ANS.push_back(mp(3, mp(3, '3')));
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> N;
	vector<Point> VV;
	for(int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		Point p;
		p.x = x;
		p.y = y;
		p.dist = abs(x) + abs(y);
		VV.push_back(p);
	}
	sort(VV.begin(), VV.end());
	for(int i = 0; i < VV.size(); ++i){
		X[i] = VV[i].x;
		Y[i] = VV[i].y;
	}
	solve();
	cout << ANS.size() << endl;
	for(int i = 0; i < ANS.size(); ++i){
		int type = ANS[i].first;
		int k = ANS[i].second.first;
		char c = ANS[i].second.second;
		if(type == 1)
			cout << type << " " << k << " " << c << endl;
		else if(type == 2)
			cout << 2 << endl;
		else if(type == 3)
			cout << 3 << endl;
	}
	return 0;
}