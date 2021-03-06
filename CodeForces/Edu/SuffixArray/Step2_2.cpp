#include <bits/stdc++.h>
using namespace std;

// optimization of right half ec sorting
// O(n logn)

/*
void count_sort(vector<int>& start, vector<int>& ec)
{
    int len = start.size();

    vector<int> tmp(len);
    vector<int> cnt(len, 0);

    for(int i : ec)  // 因為 left ec 是 right ec 向左平移 所以數量一樣
        cnt[i]++;
    
    vector<int> pos(len);
    pos[0] = 0;
    for(int i = 1; i < len; i++)
        pos[i] = pos[i-1] + cnt[i-1];

    for(auto i : start)
    {
        tmp[pos[ec[i]]++] = i;
    }

    start = tmp;   
    return ;
}


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
        for(int& i : start)
            i = (i - (1<<k) + len) % len;

        count_sort(start, ec);

        vector<int> ec_new(len);

        ec_new[0] = 0;
        for(int i = 1; i < len; i++)
        {
            pair<int, int> cur = {ec[start[i]], ec[(start[i] + (1<<k)) % len]};
            pair<int, int> prev = {ec[start[i-1]], ec[(start[i-1] + (1<<k)) % len]};

            if(cur == prev)
                ec_new[start[i]] = ec_new[start[i-1]];
            else
                ec_new[start[i]] = ec_new[start[i-1]] + 1;
        }
        ec = ec_new;
        ++k;
    }

    for(int i = 0; i < len; i++)
    {
        cout << start[i] << ' ';
    }
    return 0;


}
*/

void count_sort(vector<int> &suff, vector<int> &ec)
{
    int len = suff.size();

    vector<int> tmp(len);
    vector<int> cnt(len, 0);
    for (int i : ec)
        cnt[i]++;

    vector<int> pos(len);
    pos[0] = 0;

    for (int i = 1; i < len; i++)
        pos[i] = pos[i - 1] + cnt[i - 1];

    for (int i : suff)
    {
        tmp[pos[ec[i]]++] = i;
    }

    suff = tmp;
    return;
}

int main()
{
    string str;
    cin >> str;
    str += "$";
    int len = str.size();
    vector<int> suff(len);
    vector<int> ec(len);

    {
        vector<pair<char, int>> tmp(len);

        for (int i = 0; i < len; i++)
            tmp[i] = {str[i], i};

        sort(tmp.begin(), tmp.end());

        for (int i = 0; i < len; i++)
            suff[i] = tmp[i].second;

        ec[0] = 0;
        for (int i = 1; i < len; i++)
        {
            if (tmp[i].first == tmp[i - 1].first)
                ec[suff[i]] = ec[suff[i - 1]];
            else
                ec[suff[i]] = ec[suff[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < len)
    {
        for (int &i : suff)
            i = (i - (1 << k) + len) % len;

        count_sort(suff, ec);

        vector<int> ec_new(len);
        ec_new[0] = 0;

        for (int i = 1; i < len; i++)
        {
            pair<int, int> cur = {ec[suff[i]], ec[(suff[i] + (1 << k)) % len]};
            pair<int, int> prev = {ec[suff[i - 1]], ec[(suff[i - 1] + (1 << k)) % len]};

            if(cur == prev)
                ec_new[suff[i]] = ec_new[suff[i-1]];
            else
                ec_new[suff[i]] = ec_new[suff[i-1]] + 1;
        }
        ec = ec_new;
        ++k;
    }

    for (int i : suff)
        cout << i << ' ';
}