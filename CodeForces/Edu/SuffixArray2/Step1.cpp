#include <bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& os, vector<int>& v)
{
    for(int i : v)
        os << i << ' ';
    return os;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int len = str.size();

    vector<int> p(len);
    vector<int> ec(len);

    {
        vector<pair<char, int>> tmp(len);
        for(int i = 0; i < len; i++)
        {
            tmp[i] = {str[i], i};
        }

        sort(tmp.begin(), tmp.end());

        for(int i = 0; i < len; i++)
        {
            ec[tmp[i].second] = i;
        }
    }

    cout << str << endl << ec;

}