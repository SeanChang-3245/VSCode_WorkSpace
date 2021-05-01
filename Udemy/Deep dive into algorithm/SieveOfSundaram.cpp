#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    vector<bool> check((m-1)/2, true);

    check[0] = false;
    
    for(int i = 1; 2*i +  2*i*i < (m-1)/2; i++)
    {
        for(int j = i; i + j + 2*i*j < (m-1)/2; j++)
        {
            check[i+j+2*i*j] = false;
        }
    }

    cout << 2 << ' ';
    for(int i = 0; i < check.size(); i++)
    {
        if(check[i])
            cout << 2*i + 1 << ' ';
    }
    return 0;

}