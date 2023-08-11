#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	int s, f;
	
	cin >> n >> m;
	cin >> s >> f;
	
	vector< vector< pair<int, int> > > g(n + 1);
	
	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		
		cin >> a >> b >> t;
		
		g[a].push_back({b, t});
	}
	
	vector<int> d(n + 1, INF);
	vector<char> u(n + 1);
	
	d[s] = 0;
	
	for (int i = 0; i < n; i++)
	{
		int v = -1;
		
		for (int j = 1; j <= n; j++)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
			
		if (d[v] == INF)
			break;
		
		u[v] = true;
		
		if (v == f)
			break;
		
		for (size_t j = 0; j < g[v].size(); j++)
		{
			int to = g[v][j].first;
			int len = g[v][j].second;
			
			if (d[v] + len < d[to])
				d[to] = d[v] + len;
		}
	}
	
	
	cout << (d[f] == INF ? -1 : d[f]);
	return 0;
}
