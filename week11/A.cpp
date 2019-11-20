#include <bits/stdc++.h>
using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define N 200
string in;
int kase, n;
vector<string> a, orig;
bool first = true;
int main()
{
	cin >> kase;
	while(kase-- && cin >> n && n)
	{
		orig.clear();
		a.clear();
		//
		getchar();
		if(!first) puts("");
		first = false;
		//
		for(int i = 1; i <= n && getline(cin, in); i++)
			orig.PB(in);
		for(int i = 0; i < n && getline(cin, in); i++)
			a.PB(in);
		//
		while(!orig.empty())
		{
			if(a.back() == orig.back())
			{
				a.PPB();
				orig.PPB();
			}
			else
				orig.PPB();
		}
		for(auto i = a.rbegin(); i != a.rend(); i++)
			printf("%s\n", i->c_str());
	}
	return 0;
}