#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<int> ans(m+n);

    if(m > n)
    {
        for(int i = 0; i < m; i++)
        {
            ans[i] = i+1;
        }

        for(int i = m; i < m+n; i++)
        {
            ans[i] = -(i-m+1);
        }
        ans[m+n-1] = (m+n)*(n-m-1)/2;
    }
    else if(m < n)
    {
        for(int i = 0; i < n; i++)
        {
            ans[i] = -(i+1);
        }

        for(int i = n; i < m+n; i++)
        {
            ans[i] = (i-n+1);
        }
        ans[m+n-1] = (m+n)*(n-m+1)/2;
    }
    else
    {
        for(int i = 0; i < m+n; i+=2)
        {
            ans[i] = i+1;
            ans[i+1] = -(i+1);
        }
    }


    for(int i : ans)
        cout << i << ' ';

    return 0;
}