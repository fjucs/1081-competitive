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
#define N 10000
int n, m;
int num[N+5];
int main()
{
	while(cin >> n)
	{
		for(int i = 0; i < n && cin >> num[i]; i++);
		cin >> m;

		int mm = INT_MAX;
		int a, b;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i == j) continue;
				if(num[i]+num[j] == m && abs(num[i]-num[j]) < mm)
				{
					mm = abs(num[i]-num[j]);
					a = num[i];
					b = num[j];
				}
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", min(a,b), max(a,b));
	}
	return 0;
}