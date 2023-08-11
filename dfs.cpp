#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll MOD = 1000000000 + 7;

vector< vector<int> > g;
vector<bool> used;
int n;

void dfs(int v)
{
	used[v] = true;
	
	for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); i++)
		if (!used[*i])
			dfs(*i);
}

int main(void)
{
	int n;
	
	cin >> n;
	g.resize(n + 1);
	used.resize(n + 1);
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(2);
	
	for (int i = 1; i < n + 1; i++)
		cout << used[i] << ' ';
	
	return 0;
}
