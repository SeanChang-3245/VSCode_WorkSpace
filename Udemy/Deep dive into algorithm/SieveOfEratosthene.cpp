#include <bits/stdc++.h>
using namespace std;

void nloglogn(int m)
{
    vector<bool> check(m + 1, true);

    check[0] = check[1] = false;

    for (int i = 2; i <= sqrt(m); i++)
    {
        if (check[i] == false)
            continue;
        for (int j = 2 * i; j <= m; j += i)
        {
            check[j] = false;
        }
    }

    for (int i = 0; i <= m; i++)
    {
        if (check[i])
            cout << i << ' ';
    }
}

void n(int m)
{
    vector<int> prime;
    vector<bool> check(m+1, true);
    vector<int> lps(m+1, 1);

    check[0] = check[1] = false;

    for(int i = 2; i <= m; i++)
    {
        if(lps[i] == 1)
        {
            lps[i] = i;
            prime.push_back(i);
        }

        for(int j : prime)
        {
            if(i * j > m)  
                break;

            check[i * j] = false;
            lps[i * j] = j;
            if(j == lps[i]) 
                break;
        }
    }

    for(int i = 0; i <= m; i++)
        if(check[i])
            cout << i << ' ';
    return ;

    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    n(m);
}