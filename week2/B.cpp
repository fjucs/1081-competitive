#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "B"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
const int N = 1000;
struct Dij
{
	static const int L = ::N;
	int p[L+5];
	void init() {
		for(int i = 0; i <= L; i++) p[i] = i;
	}
	int find(int x) {
		return x == p[x] ? x : (p[x] = find(p[x]));
	}
	void uni(int a, int b) {
		p[find(a)] = find(b);
	}
	bool isSame(int a, int b) {
		return find(a) == find(b);
	}
};
struct Edge
{
	int a, b;
	double wei;
	Edge(int a, int b, double wei) {
		this->a = a;
		this->b = b;
		this->wei = wei;
	}
	friend bool operator<(const Edge &lhs, const Edge &rhs) {
		return lhs.wei < rhs.wei;
	}
};
struct Kruskal
{
	static const int N = ::N;
	static const int M = ::N*::N;
	Dij dij;           // disjoint set
	vector<Edge> g;    // graph
	vector<Edge> gmin; // MST
	void init() {
		// g.reserve(M); gmin.reserve(N);
		g.clear(); gmin.clear();
		dij.init();
	}
	void push(const Edge &e) {
		g.PB(e);
	}
	double go() {
		double rt = 0.0;
		sort(g.begin(), g.end());
		for(auto &i : g) {
			if(!dij.isSame(i.a, i.b)) {
				gmin.PB(i);
				dij.uni(i.a, i.b);
				rt += i.wei;
			}
		}
		return rt;
	}
}kru;
vector<pair<int, double> > G[N+5]; // [fr] => (to, wei)
bool vis[N+5];
//
int kase;
int n;
int x, y, peo;
struct city
{
	int x, y, man;
	friend bool operator<(const city &lhs, const city &rhs) {
		return lhs.man < rhs.man;
	}
};
vector<city> c;
double dis(const city &l, const city &r)
{
	return sqrt(pow(l.x-r.x,2)+pow(l.y-r.y,2));
}
// i -> j , Max Road
double maxR[N+5][N+5];
void dfs(int i, int now, double mr)
{
	maxR[i][now] = max(maxR[i][now], mr);
	vis[now] = true;
	for(auto &j : G[now])
	{
		if(!vis[j.F])
			dfs(i, j.F, max(mr, j.S));
	}
}
void init()
{
	kru.init();
	c.clear();
	for(int i = 0; i < n; i++)
		G[i].clear();
	memset(maxR, 0, sizeof(maxR));
}
//
int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	// printf(">> %d %d\n", Kruskal::N, Kruskal::M);
	cin >> kase;
	while(kase-- && cin >> n)
	{
		init();

		for(int i = 0; i < n && cin >> x >> y >> peo; i++)
			c.PB({x, y, peo});
		
		for(int i = 0; i < c.size(); i++)
			for(int j = 0; j < c.size(); j++)
			{
				if(i == j) continue;
				kru.push({i, j, dis(c[i], c[j])});
			}

		double sum = kru.go();
		for(auto &i : kru.gmin)
		{
			G[i.a].PB(MP(i.b, i.wei));
			G[i.b].PB(MP(i.a, i.wei));
		}
		for(int i = 0; i < n; i++)
		{
			memset(vis, 0, sizeof(vis));
			dfs(i, i, 0.0);
		}

		double ans = 0.0;
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				ans = max(ans, (c[i].man + c[j].man)/(sum - maxR[i][j]) );
		printf("%.2lf\n", ans);
	}
	return 0;
}