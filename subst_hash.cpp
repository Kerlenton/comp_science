#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll INF = 1000000000;

ll pw(ll x, ll y, ll m)
{
	if (y == 0)
		return 1;
	
	else if (y == 1)
		return x % m;
	
	else if (y % 2 == 0)
	{
		ll b = pw(x, y / 2, m) % m;
		return (b * b) % m;
	}
	
	else
	{
		return ((x % m) * (pw(x, y - 1, m) % m)) % m;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll bs = 30;
	ll c = 0;
	
	string s1;
	string s2;
	
	cin >> s1 >> s2;
	
	vector<ll> a(s1.length() + 1);
	vector<ll> b(s2.length() + 1);
	vector<ll> ans;
	
	a[0] = 0;
	b[0] = 0;
	
	for (ll i = 1; i < s1.length() + 1; i++)
		a[i] = ((MOD + a[i - 1] * bs) % MOD + (s1[i - 1] - 'a')) % MOD;
	
	for (ll i = 1; i < s2.length() + 1; i++)
		b[i] = ((MOD + b[i - 1] * bs) % MOD + (s2[i - 1] - 'a')) % MOD;
	
	for (ll i = 0; i <= s1.length() - s2.length(); i++)
	{
		if (b[s2.length()] == ((MOD + a[i + s2.length()] - (a[i] * pw(bs, (ll)s2.length(), MOD)) % MOD) % MOD))
		{
			++c;
			ans.push_back(i);
		}
	}
	
	cout << c << endl;
	
	for (vector<ll>::iterator itr = ans.begin(); itr != ans.end(); itr++)
		cout << *itr << ' ';
	
	return 0;
}
