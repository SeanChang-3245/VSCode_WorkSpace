#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

ostream& operator<<(ostream& os, list<int>& l)
{
    for(int i : l)
        os << i << ' ';
    return os;
}

list<int> n2_trace1(vector<int>& vec)
{
    int len = vec.size();

    if(len == 0)
        return list<int>(0);

    vector<int> dp(len,1);
    list<int> l;
    int tmp, ans=-1;


    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(vec[j] < vec[i])
                dp[i] = max(dp[i], dp[j]+1);
            ans = max(ans, dp[i]);
        }
    }

    int max_ele = ans;

    for(int i = len-1; i >= 0; i--)
    {
        if(dp[i] == max_ele)
        {
            l.push_front(vec[i]);
            max_ele--;
        }

    }

    return l;
}


list<int> n2_trace2(vector<int>& vec)
{
    int len = vec.size();
    if(len == 0)
        return list<int>(0);

    vector<int> trace(len, -1);
    vector<int> dp(len,1);
    list<int> l;

    int tmp, ans=-1, mx=-1, maxidx;

    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(vec[j] < vec[i] && dp[i] < dp[j]+1)
            {
                dp[i] = dp[j]+1;
                trace[i] = j;
            }
        }
        if(dp[i] > mx)
        {
            mx = dp[i];
            maxidx = i;
        }

    }

    while(maxidx != -1)
    {
        l.push_front(vec[maxidx]);
        maxidx = trace[maxidx];
    }
    return l;

}

int nlogn(vector<int>& vec)
{
    int len = vec.size();

    if(len == 0)
        return 0;


    vector<int> tail(len, 0);
    tail[0] = vec[0];
    int l = 1;

    for(int i = 1; i < len; i++)
    {
        if(vec[i] < tail[0])
            tail[0] = vec[i];
        else if(vec[i] > tail[l-1])
            tail[l++] = vec[i];
        else
            *lower_bound(tail.begin(), tail.begin()+l, vec[i]) = vec[i];
    }

    return l;
}

list<int> nlogn_trace(vector<int>& vec)
{
    int len = vec.size();

    if(len == 0)
        return list<int>(0);

    vector<int> tailidx(len, 0);
    vector<int> previdx(len, -1);

    int end = 1;


    for(int i = 1; i < len; i++)
    {
        if(vec[i] < vec[tailidx[0]])
        {
            tailidx[0] = i;
        }
        else if(vec[i] > vec[tailidx[end-1]])
        {
            previdx[i] = tailidx[end-1];
            tailidx[end++] = i;
        }
        else
        {
            int pos = lower_bound(tailidx.begin(), tailidx.begin()+end, vec[i]) - tailidx.begin();
            previdx[i] = tailidx[pos-1];
            tailidx[pos] = i;
        }
    }

    list<int> ans;

    for(int i = tailidx[end-1]; i >= 0; i = previdx[i])
    {
        ans.push_front(vec[i]);
    }

    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len;
    cin >> len;

    vector<int> vec(len);

    int tmp;
    for(int i = 0; i < len; i++)
    {
        cin >> tmp;
        vec[i] = tmp;
    }

    list<int> l = n2_trace1(vec);
    list<int> l2 = nlogn_trace(vec);

    cout << "n2 " << l;
    cout << endl;
    cout << "nlogn " << l2 <<endl<< "size"<< l2.size();

    return 0;


}

