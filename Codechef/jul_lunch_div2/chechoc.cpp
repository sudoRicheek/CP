#include <bits/stdc++.h>

using namespace std;

void solve() {
	long n , m , x , y;
	cin >> n >> m >> x >> y;

	long res = 0;

	if (n * m == 1)
	{
		cout << x << endl;
		return;
	}

	if (y / 2 >= x)
	{
		res = n * m * x;
	}
	else
	{
		if ((n * m) % 2 == 0)
		{
			res = ((n * m) / 2) * y;
		}
		else
		{
			if (x >= y )
			{
				res = ((n * m) / 2 + 1) * y;
			}
			else
			{
				res = ((n * m) / 2 + 1) * x + ((n * m) / 2) * (y - x);
			}
		}
	}
	cout << res << endl;
}



int main()
{
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}