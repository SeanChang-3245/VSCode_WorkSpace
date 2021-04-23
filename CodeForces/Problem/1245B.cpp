#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int len;
        string str;
        int r, p, s;
        cin >> len >> r >> p >> s >> str;

        int R = 0, P = 0, S = 0;

        for(int i = 0; i < len; i++)
        {
            if(str[i] == 'R')
                R++;
            else if (str[i] == 'S')
                S++;
            else
                P++;
        }

        int d1 = min(r,S);
        int d2 = min(p, R);
        int d3 = min(s, P);
        //int d4 = ceil(((float)len)/2);

        if( min(r, S) + min(p, R) + min(s, P) < (len+1) / 2 ) 
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            string ans = str;

            for(int i = 0; i < len; i++)
            {
                if(str[i] == 'R' && p)
                {
                    ans[i] = 'P';
                    --p;
                }
                else if(str[i] == 'P' && s)
                {
                    ans[i] = 'S';
                    --s;
                }
                else if(str[i] == 'S' && r)
                {
                    ans[i] = 'R';
                    r--;
                }
                else
                    ans[i] = '_';
            }

            for(int i = 0; i < len; i++)
            {
                if(ans[i] != '_')
                    continue;
                
                if(r)
                {
                    ans[i] = 'R';
                    --r;
                }
                else if(s)
                {
                    ans[i] = 'S';
                    --s;
                }
                else
                {
                    ans[i] = 'P';
                    --p;
                }
            }

            cout << "YES" << endl << ans << endl;
        }
    }
    return 0;
}