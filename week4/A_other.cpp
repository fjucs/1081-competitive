cur = hi[0];
for(int i = 0; i < n; i++)
{
	if(cur < lo[i])
		cur = lo[i];
	else if(cur > hi[i])
		cur = hi[i];
	l[i] = cur;
}