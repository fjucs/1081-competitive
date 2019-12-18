#include <bits/stdc++.h>
using namespace std;
#define N 50000
#define M 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef pair<int, int> P;
int n, m, q;
int a, b, w;
struct edge
{
	int a, b, wei;
	friend bool operator<(const edge &lhs, const edge &rhs) {
		return lhs.wei < rhs.wei;
	}
};
vector<edge> e;
vector<edge> mst;
//
vector<P> G[N+5];

int p[N+5];
void init()
{
	for(int i = 0; i <= N; i++) p[i] = i;
}
int find(int x)
{
	return x == p[x] ? x : (p[x] = find(p[x]));
}
void uni(int a, int b)
{
	p[find(a)] = find(b);
}

void kruskal()
{
	for(auto &i : e)
	{
		if(find(i.a) != find(i.b))
		{
			uni(i.a, i.b);
			mst.PB(i);
		}
	}
	for(auto &i : mst)
	{
		G[i.a].PB(MP(i.b, i.wei));
		G[i.b].PB(MP(i.a, i.wei));
	}
}

bool vis[N+5];
int MA;
void dfs(int r, int t, int Max)
{
	vis[r] = true;
	// printf("%d %d %d\n", r, t, Max);
	if(r == t) {
		MA = Max;
		return;
	}
	for(auto &i : G[r])
	{
		if(!vis[i.F])
			dfs(i.F, t, max(Max, i.S));
	}
}
bool first = true;
int main()
{
	while(cin >> n >> m)
	{
		if(!first) puts("");
		first = false;
		e.clear();
		mst.clear();
		for(int i = 0; i <= N; i++) G[i].clear();
		init();
		//
		for(int i = 0; i < m && cin >> a >> b >> w; i++)
			e.PB({a, b, w});
		sort(e.begin(), e.end());
		kruskal();
		//
		cin >> q;
		for(int i = 0; i < q && cin >> a >> b; i++)
		{
			memset(vis, 0, sizeof(vis));
			dfs(a, b, 0);
			printf("%d\n", MA);
		}
	}
}