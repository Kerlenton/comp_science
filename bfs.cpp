#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <utility>
#include <cstring>
#include <queue>
#define ll long long
 
using namespace std;
 
const ll MOD = 1000000000 + 7;

int main(void)
{
	vector< vector<int> > g;
	int n; // число вершин
	int s; // стартовая вершина
	
	queue<int> q;
	q.push(s);
	vector<bool> used(n);
	
	vector<int> d(n), p(n);
	
	used[s] = true;
	p[s] = -1;
	
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		
		for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if (!used[to])
			{
				used[to] = true;
				q.push(to);
				d[to] = d[v] + 1;
				p[to] = v;
			}
			
		}
	}
	
	return 0;
}
