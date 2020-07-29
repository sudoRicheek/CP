#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

#pragma GCC optimize "trapv"
#define M 1000000007
#define SIZE 2000006

lli g[SIZE], ps[SIZE], pssq[SIZE];

lli calc(lli n)
{
	lli lterm = lower_bound(ps, ps + SIZE, n) - ps;

	lli ans = 0;
	if (lterm > 0)
	{
		ans = pssq[lterm - 1];
	}
	ans = (ans + lterm * lterm % M * (n - ps[lterm - 1]) % M) % M;
	return ans;
}

void init()
{
	g[1] = 1, g[2] = 2, g[3] = 2;

	for (lli i = 3, pos = 4; i < SIZE; ++i)
	{
		for (lli j = 0; j < g[i] && pos < SIZE; ++j)
			g[pos++] = i;
	}

	ps[0] = 0;
	for (lli i = 1; i < SIZE; ++i)
	{
		ps[i] = ps[i - 1] + g[i];
	}

	pssq[0] = 0;
	for (lli i = 1; i < SIZE; ++i)
	{
		pssq[i] = (pssq[i - 1] + (((i * i) % M) * g[i]) % M) % M;
	}
}

int main()
{
	int t;
	cin >> t;
	init();
	while (t--)
	{
		lli l, r;
		cin >> l >> r;
		cout << (calc(r) - calc(l - 1) + M) % M << endl;
	}
	return 0;
}