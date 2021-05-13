#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v = {1,63,7,8};
    sort(v.begin(), v.end(), greater<int>());

    for(int i : v)
        cout << i << ' ';
}