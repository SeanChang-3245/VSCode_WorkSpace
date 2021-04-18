#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >>t;

    for(int x = 0; x < t; x++)
    {
        bool valid = 1;
        int len, mcnt=0, tcnt = 0;
        string str;
        cin >> len >> str;


        if(str[0] == 'M' )
        {
            cout << "NO" << endl;
            continue;
        }

        for(int i = 0; i < len; i++)
        {
            if(str[i] == 'T')
                tcnt++;
            else
            {
                mcnt++;
                if(mcnt > tcnt)
                {
                    valid = 0;
                    break;
                }

            }
        }

        if(tcnt != mcnt*2)
        {
            cout << "NO" << endl;
            continue;
        }

        mcnt = tcnt = 0;
        reverse(str.begin(), str.end());

        if(str[0] == 'M')
        {
            cout << "NO" << endl;
            continue;
        }

        for(int i = 0; i < len; i++)
        {
            if(str[i] == 'T')
                tcnt++;
            else
            {
                mcnt++;
                if(mcnt > tcnt)
                    valid = 0;
            }
        }


        if(valid)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;




    }
    return 0;

}
