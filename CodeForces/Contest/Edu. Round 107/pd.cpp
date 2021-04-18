#include <iostream>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len, k;
    cin >> len >> k;

    string pat;
    for(int i = 0; i < k-1; i++)
    {
        for(int j = i + 1; j < k; j++)
        {
            pat += 'a'+ i;
            pat += 'a'+ j;

        }
    }

    for(int i = 0; i < k; i++)
    {
        pat += 'a'+i;
        pat += 'a'+i;
    }

    string str;
    int r = pat.size();
    for(int i = 0; i < len; i++)
    {
        str+=pat[i%r];
    }
    cout << str;




}
