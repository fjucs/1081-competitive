#include <bits/stdc++.h>
using namespace std;
#define N 100
int num[N+5][N+5];
int tab[N+5][N+5];
int n;
void build()
{
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
  {
    tab[i][j] = tab[i-1][j] + tab[i][j-1] - tab[i-1][j-1] + num[i][j];
  }
}
inline int area(int i, int j, int a, int b)
{
  return tab[a][b] - tab[i-1][b] - tab[a][j-1] + tab[i-1][j-1];
}
int main()
{
  while(cin >> n)
  {
    memset(tab, 0, sizeof(tab));
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
      cin >> num[i][j];
    build();
    // for(int i = 1; i <= n; i++)
    // {
    //   for(int j = 1; j <= n; j++)
    //     printf("%d ", tab[i][j]);
    //   puts("");
    // }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        for(int a = i; a <= n; a++)
          for(int b = j; b <= n; b++)
          {
            // printf("%d ", area(i, j, a, b));
            ans = max(ans, area(i, j, a, b));
          }
    // puts("");
    printf("%d\n", ans);
  }
}