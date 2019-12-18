#include <bits/stdc++.h>
using namespace std;

#define N 100
unordered_map<string, int> m;
vector<string> suf;
int suffix[N+5];
string s, cur;
int n;
int compare(string &l, string &r)
{
	int siz = min(l.size(), r.size());
	int cnt = 0;
	for(int i = 0; i < siz; i++)
		if(l[i] == r[i]) cnt++;
	return cnt;
}
int main()
{
	cin >> n;
	while(n-- && cin >> s)
	{
		for(int i = 0; i < s.size(); i++)
		{
			cur = s.substr(i, s.size()-i+1);
			suf.push_back(cur);
		}
		sort(suf.begin(), suf.end());
		for(int i = suf.size()-1; i >= 1; i--)
			suffix[i] = compare(suf[i], suf[i-1]);
		for(int i = 0;  i < suf.size(); i++)
			printf("%s %d\n", suf[i].c_str(), suffix[i]);
	}
}