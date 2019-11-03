#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "A"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define N 15
int arr[N+5];
int kase, n;
int lcnt;
bool zero;
void step()
{
	if(lcnt > 1000) return;
	int tmp = arr[0];
	for(int i = 0; i < n-1; i++)
		arr[i] = abs(arr[i] - arr[i+1]);
	arr[n-1] = abs(arr[n-1] - tmp);

	// for(int i = 0 ; i < n; i++)
	// 	printf("%d ", arr[i]);
	// puts("");

	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(arr[i] == 0) cnt++;
	if(cnt == n)
		zero = true;
	lcnt++;
}
int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n)
	{
		zero = false;
		lcnt = 0;

		for(int i = 0; i < n && cin >> arr[i]; i++);

		while(!zero && lcnt < 1000)
			step();
		if(!zero)
			puts("LOOP");
		else
			puts("ZERO");
	}

	return 0;
}