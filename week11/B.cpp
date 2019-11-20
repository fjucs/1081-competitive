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
#define N 100
int n, m, q;
P d[N+5][N+5], zero; // [a][b] = (m, mm)
vector<P> G[N+5]; // [a] = (b, wei)
int vis[N+5];
void dijk(int r)
{
	int wei, a;
	priority_queue<P, vector<P>, greater<P>> pq; // (wei, a)
	pq.push(MP(0, r));
	while(!pq.empty())
	{
		tie(wei, a) = pq.top(); pq.pop();
		if(d[r][a].F > wei)
		{
			d[r][a].S = d[r][a].F;
			d[r][a].F = wei;
		}
		else if(d[r][a].F < wei && d[r][a].S > wei)
		{
			d[r][a].S = wei;
		}
		else
			continue;
		
		// if(vis[a] > 10) continue;
		// vis[a]++;
		
		for(auto i : G[a]) // (b, wei)
		{
			pq.push(MP(wei + i.S, i.F));
		}
	}
}
int a, b, wei;
int kase = 1;
int main()
{
	while(cin >> n >> m)
	{
		// clean
		for(int i = 0; i <= N; i++)
			G[i].clear();
		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= N; j++)
				d[i][j] = zero;
		// input
		for(int i = 0; i < m && cin >> a >> b >> wei; i++)
			G[a].PB(MP(b, wei)), G[b].PB(MP(a, wei));
		//
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				d[i][j].F = d[i][j].S = INF;
		for(int i = 0; i < n; i++)
		{
			memset(vis, 0, sizeof(vis));
			dijk(i);
		}
		//
		// for(int r = 0; r < n; r++)
		// {
		// 	for(int i = 0; i < n; i++)
		// 		printf("%d %d\n", d[r][i].F, d[r][i].S);
		// 	puts("");
		// }
		// return 0;
		cin >> q;
		printf("Set #%d\n", kase++);
		for(int i = 0; i < q && cin >> a >> b; i++)
		{
			// printf("%d %d\n", a, b);
			if(d[a][b].S == INF)
				puts("?");
			else
				printf("%d\n", d[a][b].S);
		}
	}
	return 0;
}