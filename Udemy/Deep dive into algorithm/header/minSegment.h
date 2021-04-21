#pragma once

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct node
{
    int l;
    int r;
    int val;
    int lz;

    node(int l, int r, int val, int lz)
    {
        this->l = l;
        this->r = r;
        this->val = val;
        this->lz = lz;
    }
    node()
    {
        l = r = val = lz = 0;
    }
};



class minSegment
{
private:
    vector<node> tree;
    void build(vector<int> data, int l, int r, int k);
    void rangequery(int l, int r, int k, int& ans);


public:
    minSegment(vector<int>& vec);
    int rangequery(int l, int r);
    void lvltravel();

    void singlechange(int i, int val);
    void rangechange(int l, int r, int val);

};

void minSegment::build(vector<int> data, int l, int r, int k)
{
    if(l == r)
    {
        tree[k] = node(l, r, data[l], 0);
        return;
    }

    int mid = (l+r)/2;
    build(data, l, mid, k << 1);
    build(data, mid+1, r, (k<<1)+1);

    tree[k] = node(l, r, min(tree[k << 1].val, tree[(k<<1) +1].val), 0);
    return ;
}


void minSegment::rangequery(int l, int r, int k, int& ans)   // l r 為欲搜尋的區間
{
    if(l <= tree[k].l && tree[k].r <= r)   // 該節點的區間完全包含在欲搜尋的區間中 不須遞迴到子樹
    {
        ans = min(ans, tree[k].val);
        return ;
    }

    int mid = (tree[k].l + tree[k].r) >> 1;

    if(l <= mid)  // l <= mid 表示左子樹與要搜尋的區間有重疊
    {
        rangequery(l, r, k << 1, ans);
    }

    if(mid < r)  // mid < r 表示右子樹與要搜尋的區間有重疊
    {
        rangequery(l, r, (k<<1) + 1, ans);    // 不可用 rangequery(mid+1, r, (k<<1) + 1, ans);
    }                                         // 因為 mid+1可能小於l 導致搜尋到不要的區間
    return;

}

//---------------------------------public------------------------

minSegment::minSegment(vector<int>& vec)
{
    this->tree.resize(vec.size() * 4);
    build(vec, 0, vec.size()-1, 1);
}


int minSegment::rangequery(int l, int r)
{
    int ans = INT_MAX;
    rangequery(l, r, 1, ans);
    return ans;
}



void minSegment::lvltravel()
{
    int p = 1;
    queue<int> q;
    q.push(1);

    while(q.size())
    {
        cout << tree[p].val << ' ';

        if(p*2 < tree.size()-1)
            q.push(p*2);
        
        if(p*2+1 < tree.size()-1)
            q.push(p*2+1);

        q.pop();
        p = q.front();
    }
}