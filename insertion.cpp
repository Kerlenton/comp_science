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

int main(void)
{
	int n;
	
	cin >> n;
	
	vector<int> a(n);
	
	for (int &val : a)
		cin >> val;
	
	for (int i = 1; i < n; i++)
	{
		int j = i;
		
		while (j > 0 && a[j-1] > a[j])
		{
			int tmp = a[j];
			a[j] = a[j-1];
			a[j-1] = tmp;
			
			j -= 1;
		}
	}
	
	for (int &val : a)
		cout << val << ' ';
	
	return 0;
}

//best - O(n)
//worst - O(n^2)
