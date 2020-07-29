#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

#define vi vector<long long int>

vi adjlist[300001];

void solve()
{
	lli n, k;
	cin >> n >> k;

	lli a[n + 1];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}


}



int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	int t;
	cin >> t;

	while (t--)
	{
		solve();
	}

	return 0;
}