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
#define N 30
#define SUM 30000
int in[N+5];
int dp[SUM+5];
bool pass;
int n, K=1;
void build()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = SUM; j >= 0; j--)
			if(dp[j]) dp[j + in[i]] = true;
		if(dp[in[i]]) pass = false;
		dp[in[i]] = true;
	}
}
int main()
{
	while(cin >> n)
	{
		memset(dp, 0, sizeof(dp));
		pass = true;
		//
		int pre = -1;
		for(int i = 1; i <= n && cin >> in[i]; i++)
		{
			if(pre > in[i]) pass = false;
			pre = in[i];
		}
		build();
		//
		printf("Case #%d:", K++);
		for(int i = 1; i <= n; i++) printf(" %d", in[i]);
		puts("");
		if(pass) 
			puts("This is an A-sequence.");
		else
			puts("This is not an A-sequence.");
	}
	return 0;
}