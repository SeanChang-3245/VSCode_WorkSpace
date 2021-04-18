#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    bool wrong = false;
    bool tmp = false;

    if(islower(str[0]))
    {
        for(char c : str)
        {
            if(islower(c))
            {
                cout << str;
                return 0;
            }
        }

    }

    for(char c : str)
    {
        if(isupper(c))
        {
            wrong = true;
            break;
        }

    }

    if(wrong)
    {
        for()
    }

}
