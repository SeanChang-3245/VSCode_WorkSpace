#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, k;
    cin >> m >> k;
    vector<int> vec(m);

    for(int i = 0; i < m; i++)
    {
        cin >> vec[i];
    }

    int sum = 0;
    int idx = 0;
    for(int i = 0; i < k; i++)  
        sum += vec[i];

    int min = sum;

    for(int i = k; i < m; i++)
    {
        sum = sum + vec[i] - vec[i-k];
        if(sum < min)
        {
            min = sum;
            idx = i-k+1;
        }
    }
    cout << idx+1;
    return 0;
}