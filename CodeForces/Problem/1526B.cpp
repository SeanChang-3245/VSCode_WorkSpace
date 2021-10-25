#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll x(int bit)
{
    ll ans = 1;
    for(int i = 1; i < bit; i++)
        ans = ans*10 + 1;
    return ans;
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
        bool valid = true;


        for(int i = 0; i < len-1; i++)
        {
            char c = str[i];

            for(int j = i; j < len && valid; j++)
            {
                if(c > str[j])
                {
                    valid = false;
                    break;
                }
                else
                {
                    str[j] = str[j] - c + '0';
                }
            }
        }
        
        

        if(valid && str[len-1] == '0')
            cout << "YES" << endl;
        else  
            cout << "NO" << endl;
    }
    return 0;
}