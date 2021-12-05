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
#define ll long long
 
using namespace std;
 
const ll MOD = 1000000000 + 7;

void so(vector<int> &a, int l, int r)
{	
	vector<int> t(r - l);
	
	if (l + 1 == r)
		return;
	
	int m = (l + r) / 2;
	
	so(a, l, m);
	so(a, m, r);
	
	int i = l;
	int j = m;
	int p = 0;
	
	while (i < m && j < r)
	{
		if (a[i] > a[j])
		{
			t[p] = a[j];
			++j;
		}
		
		else
		{
			t[p] = a[i];
			++i;
		}
		
		++p;
	}
	
	while (i < m)
	{
		t[p] = a[i];
		
		++p;
		++i;
	}
	
	while (j < r)
	{
		t[p] = a[j];
		
		++p;
		++j;
	}
	
	for (int k = l; k < r; k++)
		a[k] = t[k - l];
}

int main(void)
{
	int n;
	
	cin >> n;
	
	vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	so(a, 0, n);
	
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	
	return 0;
}
//O(nlogn)
