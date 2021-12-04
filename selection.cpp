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
	
	for (int i = 0; i < n; i++)
	{
		int min = i;
		
		for (int j = i; j < n; j++)
			if (a[min] > a[j])
				min = j;
			
		int tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}
	
	for (int &val : a)
		cout << val << ' ';
	
	return 0;
}

//O(n^2)
