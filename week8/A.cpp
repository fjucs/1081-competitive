#include <bits/stdc++.h>

using namespace std;

#define PROB "A"
#define TESTC ""

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
int kase, T=1;
string s, t;
int scnt, tcnt;
vector<int> idx[2];
int ans;
int main()
{
	cin >> kase;
	while(kase-- && cin >> s >> t)
	{
		ans = 0;
		scnt = tcnt = 0;
		for(int i = 0; i < 2; i++) idx[i].clear();
		//
		for(int i = 0; i < s.size(); i++)
			if(s[i] == '0' && t[i] == '1')
				idx[0].PB(i); // 0->1
			else if(s[i] == '1' && t[i] == '0')
				idx[1].PB(i); // 1->0
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '1') scnt++;
			if(t[i] == '1') tcnt++;
		}
		//
		printf("Case %d: ", T++);
		if(scnt <= tcnt)
		{
			ans += max(idx[0].size(), idx[1].size());
			// for(int i = 0; i < idx[1].size(); i++)
			// 	ans++;
			// if(idx[0].size() != idx[1].size())
			// 	for(int i = idx[1].size(); i < idx[0].size(); i++)
			// 		ans++;
			for(int i = 0; i < s.size(); i++)
				if(s[i] == '?') ans++;
			printf("%d\n", ans);
		}
		else
			printf("-1\n");
	}
	return 0;
}