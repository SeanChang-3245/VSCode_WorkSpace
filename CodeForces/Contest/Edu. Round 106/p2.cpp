#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++)
    {
        string str;
        cin >> str;

        bool z, o, zo;
        z = o = zo = true;

        for(int i = 0; i < str.size() - 1; i++)
        {
            if(str[i] == '0' && str[i+1] == '0')
                o = false;

            if(str[i] == '1' && str[i+1] == '1')
                z = false;
        }

        int i = 0;
        while(!(str[i] == '1' && str[i+1] == '1') && i < str.size()-1)
        {
            ++i;
        }
        for(; i < str.size() -1; i++)
        {
            if(str[i] == '0' && str[i+1] == '0')
            {
                zo = false;
                break;
            }
        }



        if(o || z || zo)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

    }
    return 0;


}
