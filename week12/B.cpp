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
#define N 1000000
struct C
{
	int h, w;
	friend bool operator<(const C& lhs, const C& rhs) {
		return lhs.w < rhs.w;
	}
	const C& operator=(const C& rhs) {
		this->h = rhs.h;
		this->w = rhs.w;
		return *this;
	}
};
vector<C> city;
vector<C> lis;
int a[N+5], b;
int n, kase;
int main()
{
	cin >> kase;
	for(int K = 1; K <= kase && cin >> n; K++)
	{
		lis.clear();
		//
		for(int i = 0; i < n && cin >> a[i]; i++);
		for(int i = 0; i < n && cin >> b; i++)
			city.PB({a[i], b});
		//
		for(auto &i : city)
		{
			if(!lis.empty())
			{
				lis.PB(i);
				continue;
			}
			if(lis.back() < i)
				lis.PB(i);
			else
				*lower_bound(lis.begin(), lis.end(), i) = i;
		}
		for(auto &i : lis)
			printf("%d %d\n", i.h, i.w);
	}
	return 0;
}