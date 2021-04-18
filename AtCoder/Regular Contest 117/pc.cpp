#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    string str, tmp;
    cin >> str;

    while(1)
    {
        for(int i = 0; i < str.size()-1; i++)
        {
            if(str[i] == str[i+1])
            {
                tmp += str[i];
            }
            else
            {
                if(str[i] == 'R' && str[i+1] == 'B')
                    tmp += 'W';
                else if(str[i] == 'B' && str[i+1] == 'R')
                    tmp += 'W';
                else if(str[i] == 'W' && str[i+1] == 'R')
                    tmp += 'B';
                else if(str[i] == 'R' && str[i+1] == 'W')
                    tmp += 'B';
                else if(str[i] == 'B' && str[i+1] == 'W')
                    tmp += 'R';
                else if(str[i] == 'W' && str[i+1] == 'B')
                    tmp += 'R';    
            }

        }

        if(tmp.size() == 1)
        {
            cout << tmp;
            break;
        }

        str = tmp;
        tmp = "";      
    }
    return 0;
}