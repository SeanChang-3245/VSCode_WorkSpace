#include <bits/stdc++.h>
using namespace std;

#define endl '\n'



void print(vector<vector<bool>>& dp, vector<int>& num, vector<int>&ans, int i, int j)
{
    if(i < 0)
        return;

    if(j == 0)
    {
        for(int i : ans)
            cout << i << ' ';
        cout << endl;
        return;
    }

    if(i-1 >= 0)
    {
        if(dp[i-1][j] == true)
        {
            print(dp, num, ans, i-1, j);
        }   

        if(j -num[i-1] >= 0 && dp[i-1][j-num[i-1]])
        {
            ans.push_back(num[i-1]);
            print(dp, num, ans, i-1, j - num[i-1]);
            ans.erase(--ans.end());
        }
    }
}


int main()
{
//    ios::sync_with_stdio(false);
  //  cin.tie(0);

    int m, sum;
    bool valid = false;
    cin >> m >> sum;
    vector<int> num(m);
    
    for(int& i : num) cin >> i;

    vector<vector<bool>> dp(m+1, vector<bool>(sum+1, false));

    for(int i = 0; i < m+1; i++)
    {
        for(int j = 0; j < sum+1; j++)
        {
            if(j == 0)
            {
                dp[i][j] = true;
                continue;
            }

            if(i == 0) break;

            if(num[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = (dp[i-1][j]) || (dp[i-1][j-num[i-1]]);
            


        }

        if(dp[i][sum])
        {
            valid = true;
            break;
        }
    }

    if(valid)
    {
        cout << "YES" << endl;
        vector<int> ans;
        print(dp, num, ans, m, sum);
    }       
    else
        cout << "NO";

    

    return 0;
}
