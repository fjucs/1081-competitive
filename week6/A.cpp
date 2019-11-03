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
#define N 500
int num[N+5];
int kase, n, ni;
int main()
{
	cin >> kase;
	while(kase-- && cin >> n)
	{
		ni = 0;
		for(int i = 0; i < n && cin >> num[i]; i++);

		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				if(num[i] > num[j])
					ni++;

		if(n % 2 != 0 && ni % 2 != 0)
			puts("impossible");
		else
			puts("possible");
	}
	return 0;
}