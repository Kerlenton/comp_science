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
 
const ll MOD = 998244353;
const ll INF = 1000000000;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	
	cin >> s;
	
	vector<int> z(s.length());
	vector<int> pref(s.length());
	
	int l = -1;
	int r = -1;
	
	z[0] = 0;
	
	cout << 0 << ' ';
	
	for (int i = 1; i < s.length(); i++)
	{
		z[i] = 0;
		
		if (i < r)
			z[i] = min(z[i - l], r - i);
		
		while (z[i] + i < s.length() && s[z[i]] == s[i + z[i]])
			++z[i];
		
		if (i + z[i] >= r)
		{
			r = i + z[i];
			l = i;
		}
		
		cout << z[i] << ' ';
	}
	
	cout << endl;
	pref[0] = 0;
	
	cout << 0 << ' ';
	for (int i = 1; i < s.length(); i++)
	{
		int t = i - 1;
		
		while (pref[t] != 0 && s[pref[t]] != s[i])
			t = pref[t] - 1;
		
		if (s[pref[t]] == s[i])
			pref[i] = pref[t] + 1;
		
		else
			pref[i] = 0;
		
		cout << pref[i] << ' ';
	}
	
	return 0;
}
