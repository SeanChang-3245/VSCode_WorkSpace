#pragma once


#include "minSegment.h"



int bf(vector<int>& vec, int l, int r)
{
    int m = INT_MIN;
    for(int i = 0; i <= r; i++)
    {
        if(vec[i] > m)
            m = vec[i];
    }
    return m;
}


int bf_min(vector<int>& vec, int l, int r)
{
    int m = INT_MAX;
    for(int i = 0; i <= r; i++)
    {
        if(vec[i] < m)
            m = vec[i];
    }
    return m;
}


int dp_min(vector<int>& vec, int l, int r)
{
    int len = vec.size();

    vector<vector<int>> dp(len, vector<int>(len, 0));

    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            if(i == j)
            {
                dp[i][j] = vec[i];
            }
            else
            {
                dp[i][j] = min(dp[i][j-1], vec[j]);
            }
        }
    }
    return dp[l][r];
}





void table(vector<int>& data);
vector<vector<int>> sparse;
bool built = false;
int sparsetable(vector<int>& data, int l, int r)
{
    if (!built)
    {
        table(data);
        built = true;
    }

    int len = r - l + 1;
    int k = log2(len);
    int remain = len - pow(2, k);
    
    return min(sparse[l][k], sparse[l+remain][k]);

}

void table(vector<int>& data)
{
    int len = data.size();
    int wid = log2(len)+1;
    sparse.resize(len);

    for(int i = 0; i < len; i++)
    {
        sparse[i] = vector<int>(wid);
    } 
    
    for(int i = 0; i < wid; i++)
    {
        for(int j = 0; j < len - (pow(2, i-1) - 1); j++)
        {
            if(i == 0)
            {
                if(j >= len)
                    continue;
                sparse[j][i] = data[j];
                continue;
            }
            sparse[j][i] = min(sparse[j][i-1], sparse[j + pow(2, i-1)][i-1]); 
        }
    }

}
