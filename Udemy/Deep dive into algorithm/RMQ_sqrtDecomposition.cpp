#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


int query(vector<int>& data, vector<int>& lookup, int l, int r)
{
    int len = data.size();
    int slen = sqrt(len);
    int ans = INT_MAX;

    int i = l;

    while(i % slen != 0 && i <= r)
    {
        ans = min(ans, data[i]);
        ++i;
    }

    while(i + slen <= r)
    {
        ans = min(ans, lookup[i/slen]);
        i += slen;
    }

    while(i <= r)
    {
        ans = min(ans, data[i]);
        ++i;
    }
    return ans;
}


int main()
{
    //ios_base::sync_with_stdio(false);
  //  cin.tie(0);

    int len, sqrtlen;
    cin >> len;
    sqrtlen = sqrt(len);

    vector<int> vec(len);
    vector<int> lookup;

    for(int& i : vec)
        cin >> i;

    int tmp = INT_MAX;
    for(int i = 0; i < len; i++)
    {
        if(i % sqrtlen == 0 && i != 0)
        {
            lookup.push_back(tmp);
            tmp = INT_MAX;
        }
        tmp = min(tmp, vec[i]);           
    }
    lookup.push_back(tmp);

    cout << "lookup: ";
    for(int i : lookup)
        cout << i << ' ';
    cout << endl;


    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len ; j++)
        {
            printf("[%d, %d] = %d", i , j, query(vec, lookup, i, j));
            cout << endl;
        }
        cout << endl;
    }
    

}