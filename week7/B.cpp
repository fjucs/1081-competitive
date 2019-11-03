#include <bits/stdc++.h>
using namespace std;
#define N 50000
int kase, n;
int siz[N+5];
string s;
int count(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt++;
		x /= 10;
	}
	return cnt;
}
void build()
{
	s += ' '; // 1-index
	for(int i = 1; i <= N; i++)
	{
		s += to_string(i);
		siz[i] = siz[i-1] + count(i);
	}
}
int main()
{
	build();
	cin >> kase;
	while(kase-- && cin >> n)
	{
		int i = 1;
		while(n > siz[i])
		{
			n -= siz[i];
			i++;
		}
		printf("%c\n", s[n]);
	}
}