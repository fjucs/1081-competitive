#include <bits/stdc++.h>

using namespace std;

#define PROB ""
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
#define N 1000
int sc[N+5][5];
int R[N+5];
int n;
float tmp;

int getLE(int cur, int a, int b, int c, bool big)
{
	int cmb[] = {0, a, b, c, a+b, a+c, b+c, a+b+c}; // all comb
	sort(cmb, cmb+8);
	for(int i = 7; i >= 0; i--)
		if(cur > cmb[i] || (big && cur == cmb[i])) return cmb[i];
	return -1;
}

int main()
{
	int T=1;
	while(cin >> n && n)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3 && cin >> tmp; j++) // scores
				sc[i][j] = round(tmp * 100);
		for(int i = 1; i <= n && cin >> R[i]; i++); // ids
		//
		int ans = sc[R[1]][1]+sc[R[1]][2]+sc[R[1]][3];
		for(int i = 2; i <= n && ans >= 0; i++)
			ans = getLE(ans, sc[R[i]][1], sc[R[i]][2], sc[R[i]][3], R[i-1] < R[i]);
		printf("Case %d: ", T++);
		if(ans == -1 || !ans) puts("No solution");
		else printf("%.2f\n", ans / 100.0);
	}
	return 0;
}