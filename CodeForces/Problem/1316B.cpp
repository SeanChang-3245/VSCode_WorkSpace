#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

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
        string smallest;
        int cnt = 1;
        cin >> len >> str;
        smallest = str;

        
        for(int i = 1; i < len; i++)
        {
            rotate(str.begin(), str.begin() + 1, str.end());

            if(str < smallest)
            {
                smallest = str;
                cnt = i+1;
            }
        }

        cout << smallest << endl << cnt << endl;

    }

    return 0;
}