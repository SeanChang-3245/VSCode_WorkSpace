#include <bits/stdc++.h>
using namespace std;


vector<int> BIT;

int lowbit(int x)
{
    return x & (-x);
}

void modify(int pos, int v)
{
    while(pos < BIT.size())
    {
        BIT[pos] += v;
        pos += lowbit(pos);
    }   
}

int query(int pos)
{
    int sum = 0;
    while(pos > 0)
    {
        sum += BIT[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr)
        cin >> i;

    BIT.resize(n+1);

    for(int i = 1; i < n+1; i++)
    {
        modify(i, arr[i-1]);
    }

    cout << query(5) << endl;
    modify(3, 6);
    cout << query(5) << endl;
    cout << query(0);

    
    return 0;
}

//12  2 1 1 3 2 3 4 5 6 7 8 9