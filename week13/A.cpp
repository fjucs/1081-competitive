#include <bits/stdc++.h>
using namespace std;
double d;
string s;
int a, b, tmp;
int A, B;
int main()
{
	while(cin >> s && s != "0")
	{
		// cout << s << '\n';
		s = s.substr(2, s.size()-5);
		A = B = INT_MAX;
		for(int i = 0; i < s.size(); i++)
		{
			tmp = a = b = 0;
			// b
			for(int j = 0; j < s.size()-i; j++)
			{
				b *= 10;
				b += 9;
			}
			for(int j = 0; j < i; j++)
				b *= 10;
			// a
			for(int j = 0; j < s.size(); j++)
			{
				a *= 10;
				a += s[j]-'0';
			}
			for(int j = 0; j < i; j++)
			{
				tmp *= 10;
				tmp += s[j]-'0';
			}
			a -= tmp;
			//
			int g = __gcd(a, b);
			// printf("%d %d %d", a, b, g);
			a /= g;
			b /= g;
			// printf(" > %d %d\n", a, b);
			if(b < B)
			{
				B = b;
				A = a;
			}
		}
		printf("%d/%d\n", A, B);
	}
}