#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vec(5, 0);

	for(int i : vec)
		cout << i << ' ';
	cout << endl;
	vec.erase(--vec.end());
	for(int i : vec)
		cout << i << ' ';
}