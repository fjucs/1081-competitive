#include <bits/stdc++.h>

using namespace std;

#define PROB "B"
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
#define N 200000
int BIT[N+5]; // Bit-indexed Tree
int n, arr[N+5];
#define lowbit(x) ((x)&(-x))
// void init() {
// 	memset(BIT, 0, sizeof(BIT));
// 	for(int x = 1; x <= n; ++x) {
// 		BIT[x] += arr[x];
// 		int y = x + lowbit(x);
// 		if(y <= n) arr[y] += arr[x];
// 	}
// }
inline void update(int x, int v)
{
	for(; x <= N; x += lowbit(x))
		BIT[x] += v;
}
inline int query(int x)
{
	int ans = 0;
	for(; x; x -= lowbit(x))
		ans += BIT[x];
	return ans;
}
int T=1, tmp;
string in;
char opt;
int a, b;
int main()
{
	while(cin >> n && n)
	{
		memset(BIT, 0, sizeof(BIT));
		for(int i = 1; i <= n && cin >> arr[i]; i++)
			update(i, arr[i]);
		// init();
		getchar();
		//
		printf("%sCase %d:\n", T>1?"\n":"", T);
		T++;
		while(getline(cin, in) && in != "END"
			&& ~sscanf(in.c_str(), "%c %d %d", &opt, &a, &b))
		{
			switch(opt)
			{
			case 'M':
				printf("%d\n", query(b)-query(a-1)); // [a, b]
			break;

			case 'S':
				update(a, -arr[a]);
				update(a, b);
				arr[a] = b;
			break;
			}
			
		}
	}
	return 0;
}