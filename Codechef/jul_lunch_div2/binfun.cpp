#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define vi vector<long long int>
#define INF 1000000000000



long long bincon(long long x, long long y, int nx, int ny)
{
	return (((x << ny) | y) - ((y << nx) | x));
}

int cntbit(long long n) {
	return (int)(log2(n)) + 1;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		long long int arr[n + 1];

		vi maxbit(32, 0);
		vi minbit(32, INF);

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
			int len = cntbit(arr[j]);
			maxbit[len] = max(maxbit[len], arr[j]);
			minbit[len] = min(minbit[len], arr[j]);
		}

		long long ans = -1;

		for (int i = 1; i < 32; ++i)
		{
			for (int j = 1; j < 32; ++j)
			{
				long long X = maxbit[i];
				long long Y = minbit[j];

				if (X == 0 or Y == INF)
				{
					continue;
				}

				long long diff = bincon(X, Y, i, j);
				ans = max(ans, diff);
			}
		}

		cout << ans << endl;

	}
	return 0;
}