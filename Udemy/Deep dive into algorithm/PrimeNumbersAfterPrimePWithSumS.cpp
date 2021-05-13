#include <bits/stdc++.h>
using namespace std;

vector<int> use;

void sol(vector<int>& prime, int sum, int n, int p)
{
    if(n == 0)
    {
        if(sum == 0)
        {
            for(int i : use)
                cout << i << ' ';
            cout << endl;
        }
        return;
    }
    
    for(int i : prime)
    {
        if(sum - i >= 0 && i > p && (use.empty() || i > *use.rbegin()))
        {
            use.push_back(i);
            sol(prime, sum - i, n-1, p);
            use.erase(--use.end());
        }
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p, s;
    cin >> n >> p >> s;

    vector<bool> check(s+1, true);
    vector<int> lps(s+1, 1);
    vector<int> prime;

    check[0] = check[1] = false;
    for(int i = 2; i <= s; i++)
    {
        if(lps[i] == 1)
        {
            lps[i] = i;
            prime.push_back(i);
        }
        for(int j : prime)
        {
            if(i * j > s)
                break;

            check[i*j] = false;
            lps[i*j] = j;
            if(j == lps[i])
                break;
        }
    }
    


    sol(prime, s, n, p);




}