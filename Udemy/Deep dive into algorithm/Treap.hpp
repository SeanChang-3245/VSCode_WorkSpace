#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    int pri;
    node *lc;
    node *rc;

    node()
    {
        key = pri = 0;
        lc = rc = nullptr;
    }
    node(int v, int p, node *l, node *r)
    {
        key = v;
        pri = p;
        lc = l;
        rc = r;
    }
};

class treap
{
private:
    node *root;
    node *l_rotate(node *cur);
    node *r_rotate(node *cur);
    void inorder(node *cur);
    node *insert(int key, node *cur);
    node *del(int key, node *cur);
    node *_find(int tar);
    int height(node *cur);

public:
    void inorder();
    void insert(int key);
    void del(int key);
    bool find(int tar);
    int height();

    treap()
    {
        this->root = nullptr;
    }

    treap(vector<int> &vec)
    {
        this->root = nullptr;
        for (int i = 0; i < vec.size(); i++)
        {
            insert(vec[i]);
        }
    }
};

void treap::inorder()
{
    node *cur = this->root;
    inorder(cur);
    cout << endl;
    return;
}

void treap::inorder(node *cur)
{
    if (cur == nullptr)
        return;

    inorder(cur->lc);
    cout << cur->key << ' ';
    inorder(cur->rc);
    return;
}

bool treap::find(int tar)
{
    node *cur = this->root;

    while (cur != nullptr)
    {
        if (cur->key == tar)
            return true;
        else if (cur->key < tar)
            cur = cur->rc;
        else
            cur = cur->lc;
    }
    return false;
}

void treap::insert(int key)
{
    if (this->root == nullptr)
    {
        this->root = new node(key, rand(), nullptr, nullptr);
        return;
    }

    this->root = insert(key, this->root);
    return;
}

node *treap::insert(int key, node *cur)
{
    if (cur == nullptr)
    {
        return new node(key, rand(), nullptr, nullptr);
    }

    if (key > cur->key)
    {
        //insert會return右節點的指標
        cur->rc = insert(key, cur->rc);     
        
        //在insert之前 pri 保有 max_heap 的性質，而修改只發生在右子樹
        //故只需判斷右節點之pri是否違反 max_heap，並適時予以左旋轉 
        if (cur->pri < cur->rc->pri)
        {
            cur = l_rotate(cur);
        }
    }
    else
    {
        cur->lc = insert(key, cur->lc);

        if (cur->pri < cur->lc->pri)
        {
            cur = r_rotate(cur);
        }
    }
    return cur;
}

node *treap::l_rotate(node *cur)
{
    node *r = cur->rc;
    node *rclc = cur->rc->lc;

    r->lc = cur;
    cur->rc = rclc;

    return r;
}

node *treap::r_rotate(node *cur)
{
    node *l = cur->lc;
    node *lcrc = cur->lc->rc;

    l->rc = cur;
    cur->lc = lcrc;

    return l;
}

void treap::del(int key)
{
    if (find(key) == false)
        return;

    this->root = del(key, this->root);
}

node *treap::del(int key, node *cur)
{
    if (cur == nullptr)
        return nullptr;

    if (key > cur->key)
        cur->rc = del(key, cur->rc);
    else if (key < cur->key)
        cur->lc = del(key, cur->lc);
    else if (key == cur->key)
    {
        if (cur->lc == nullptr && cur->rc == nullptr)
            return nullptr;
        else if (cur->lc == nullptr && cur->rc != nullptr)
            return cur->rc;
        else if (cur->lc != nullptr && cur->rc == nullptr)
            return cur->lc;
        else
        {
            // 若要刪除的節點的左右子節點皆不為nullptr，則藉由旋轉
            // 將其不斷下移直到有其中一個子節點為nullptr
            // 且在旋轉時仍要保持max_heap性質
            if (cur->lc->pri < cur->rc->pri) //右節點pri較大故左旋轉
            {
                cur = l_rotate(cur);
                cur->lc = del(key, cur->lc);
            }
            else
            {
                cur = r_rotate(cur);
                cur->rc = del(key, cur->rc);
            }
        }
    }
    return cur;
}

node *treap::_find(int tar)
{
    node *cur = this->root;

    while (cur != nullptr)
    {
        if (cur->key == tar)
            return cur;
        else if (cur->key < tar)
            cur = cur->rc;
        else
            cur = cur->lc;
    }
    return nullptr;
}

int treap::height()
{
    return height(this->root);
}

int treap::height(node *cur)
{
    if (cur == nullptr)
        return 0;

    return max(height(cur->lc), height(cur->rc)) + 1;
}