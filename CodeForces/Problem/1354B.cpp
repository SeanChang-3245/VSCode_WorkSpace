#include <bits/stdc++.h>
using namespace std;


bool check(int cnt[])
{
    if(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        int len = str.size();

        if(len < 3)
        {
            cout << 0 << endl;
            continue;
        }

        int l = 0, r = 1, ans = INT_MAX;
        int cnt[3] = {0,0,0};

        cnt[str[0]-'1']++;
        

        for(; r < len; r++)
        {
            cnt[str[r]-'1']++;

            if(str[l] == str[r])
            {
                while(l <= r && cnt[str[l]-'1'] > 1)
                {
                    --cnt[str[l]-'1'];
                    ++l;
                }
            }
            
            if(check(cnt))
            {
                ans = min(ans, r-l+1);
            }
            
        }

        if(ans == INT_MAX)
            cout << 0 << endl;
        else
            cout << ans << endl;


    }
}