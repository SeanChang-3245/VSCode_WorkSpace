#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    str += '$';
    int len = str.size();

    vector<int> start(len); // storing the starting idx of the suffixes
    vector<int> ec(len);    // equivalence class


    {  // k = 0
        vector<pair<char, int>> tmp(len);  // pair<char, idx>

        for(int i = 0; i < len; i++)  tmp[i] = {str[i], i};

        sort(tmp.begin(), tmp.end()); // sort by lexicography
        
        for(int i = 0; i < len; i++)  start[i] = tmp[i].second;  // start is also sorted by lexicography

        ec[start[0]] = 0;  // the element which has the smallest lexicography has the smallest class
                           // start stores the starting idx of the suffixes, and the idxs(every idx represent a suffix) are sorted by lexicography
        for(int i = 1; i < len; i++)  
        {
            if(tmp[i].first == tmp[i-1].first)         
                ec[start[i]] = ec[start[i-1]]; //  ec[tmp[i].second] = ec[tmp[i-1].second]    tmp[i].second == idx
            else
                ec[start[i]] = ec[start[i-1]] + 1;
        }  // build the ec
    }

    
    // transition from k to k+1
    int k = 0;
    while((1 << k) < len)
    {
        vector<pair<pair<int, int>, int>> tmp(len);    // pair< pair<left half ec, right half ec>, idx>

        for(int i = 0; i < len; i++)  // left part start from i, right part start from (i + (k<<1)) % len
        {
            tmp[i] = {{ec[i], ec[(i + (1<<k)) % len]}, i};  // assume the string is cyclic, so mod len
        }

        sort(tmp.begin(), tmp.end()); 

        for(int i = 0; i < len; i++) start[i] = tmp[i].second;

        ec[start[0]] = 0;
        for(int i = 1; i < len; i++)
        {
            if(tmp[i].first == tmp[i-1].first)
                ec[start[i]] = ec[start[i-1]];
            else
                ec[start[i]] = ec[start[i-1]] + 1;
        }
        ++k;
    }

    for(int i = 0; i < len; i++)
    {
        cout << start[i] << ' ';
    }
    return 0;


}