#include <bits/stdc++.h>
using namespace std;
#define N 1000000
int kase, n;
int lo[N+5], hi[N+5]; // floor and ceiling
int l[N+5], r[N+5];   // highest possible oil (from left or right)
int cur;
int main()
{
	cin >> kase;
	while(kase-- && cin >> n)
	{
		memset(lo, 0, sizeof(lo));
		memset(hi, 0, sizeof(hi));

		for(int i = 0; i < n && cin >> lo[i]; i++);
		for(int i = 0; i < n && cin >> hi[i]; i++);
		// left
		cur = hi[0];
		for(int i = 0; i < n-1; i++)
		{
			l[i] = cur;
			// The next floor is higher than the current
			if(lo[i+1] > cur)
				cur = lo[i+1];
			// The next ceiling is lower than the current
			else if(hi[i+1] < cur)
				cur = hi[i+1];
		}
		l[n-1] = cur;
		// right
		cur = hi[n-1];
		for(int i = n-1; i >= 1; i--)
		{
			r[i] = cur;
			if(lo[i-1] > cur)
				cur = lo[i-1];
			else if(hi[i-1] < cur)
				cur = hi[i-1];
		}
		r[0] = cur;

		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += min(l[i], r[i]) - lo[i];
		printf("%d\n", ans);
	}
}