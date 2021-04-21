#include <iostream>
#include <vector>
using namespace std;

/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, onecnt = 0;
    cin >> m;
    vector<int> vec(m);
    vector<int> one(m+1, 0);
    vector<int> zero(m+1, 0);

    for(int i = 0; i < m; i++)
    {
        cin >> vec[i];
        
        if(vec[i] == 1)
        {
            one[i+1] = one[i] + 1;
            zero[i+1] = zero[i];
            ++onecnt;
        }
        else
        {
            zero[i+1] = zero[i] +1;
            one[i+1] = one[i];
        }
            
    }

    int ans = INT_MIN;
    for(int i = 0; i <= m; i++)
    {
        for(int j = i+1; j <= m; j++)
        {
            ans = max(onecnt + zero[j]-zero[i] - (one[j]-one[i]), ans);
        }
    }
    cout << ans;
    return 0;


}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, ans, onecnt = 0;
    cin >> m;
    vector<int> vec(m);
    vector<int> dp(m);

    for(int i = 0; i < m; i++)
    {
        cin >> vec[i];
        if(vec[i] == 1)
        {
            vec[i] = -1;
            ++onecnt;
        }
        else
        {
            vec[i] = 1;
        }
    }
    dp[0] = vec[0]; 
    ans = dp[0];
    for(int i = 1; i < m; i++)
    {
        dp[i] = max(vec[i], vec[i] + dp[i-1]);
        ans = max(ans, dp[i]);
    }

    cout << ans + onecnt;
    return 0;



}