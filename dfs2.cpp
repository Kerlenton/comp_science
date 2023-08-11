#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll MOD = 1000000000 + 7;

vector< vector<int> > g;
vector<bool> used;
vector<int> p;
int n;

void dfs(int v, int t)
{
	p.push_back(v);
	used[v] = true;
	
	if (v == t)
	{
		for (vector<int>::iterator i = p.begin(); i != p.end(); i++)
			cout << *i << ' ';
		cout << endl;
	}
	
	for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); i++)
		if (!used[*i])
			dfs(*i, t);
		
		

	p.pop_back();
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
	
	dfs(1, 3);
	return 0;
}
