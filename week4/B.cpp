#include <bits/stdc++.h>
using namespace std;
#define N 100
int q[N+5][8], cnt;
bool L[20], R[20], row[10];
int tmp[8];

void build(int i)
{
	if(i == 8)
	{
		for(int a = 0; a < 8; a++)
			q[cnt][a] = tmp[a];
		cnt++;
		return;
	}
	for(int j = 0; j < 8; j++)
	{
		int l = i+j, r = 7-(i-j);
		if(!L[l] && !R[r] && !row[j])
		{
			L[l] = R[r] = row[j] = true;
			tmp[i] = j;
			build(i+1);
			L[l] = R[r] = row[j] = false;
		}
	}
}
int kase;
int wei[8][8];
int main()
{
	build(0);
	cin >> kase;
	while(kase--)
	{
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8 && cin >> wei[i][j]; j++);

		int ans = 0, tmp;
		for(int i = 0; i < cnt; i++)
		{
			tmp = 0;
			for(int j = 0; j < 8; j++)
				tmp += wei[j][q[i][j]];
			ans = max(ans, tmp);
		}
		printf("%5d\n", ans);
	}
}