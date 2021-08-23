#include <bits/stdc++.h>
using namespace std;

struct node
{
    bool EndOfWord;
    vector<node *> child;

    node(bool a)
    {
        EndOfWord = a;
        child.resize(26);
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class trie
{
private:
    node *root;
    node *del(string &key, node *cur, int idx);

public:
    void insert(string key);
    bool search(string key);
    void del(string &key);

    trie()
    {
        this->root = new node(false);
    }
};

void trie::insert(string key)
{
    node *cur = this->root;

    // 若此時trie沒有任何節點，建立一個node並賦予給root
    if (cur == nullptr)
    {
        this->root = new node(false);
    }

    int key_len = key.size();

    for (int i = 0; i < key_len; i++)
    {
        if (cur->child[key[i] - 'a'] == nullptr)
        {
            cur->child[key[i] - 'a'] = new node(false);
        }
        cur = cur->child[key[i] - 'a'];
    }
    cur->EndOfWord = true;
}

bool trie::search(string key)
{
    node *cur = this->root;
    int key_len = key.size();

    if (cur == nullptr)
    {
        return false;
    }

    for (int i = 0; i < key_len; i++)
    {
        if (cur->child[key[i] - 'a'] == nullptr)
        {
            return false;
        }
        cur = cur->child[key[i] - 'a'];
    }

    if (cur->EndOfWord == false)
        return false;
    return true;
}

bool no_child(node* cur)
{
    for(int i = 0; i < 26; i++)
    {
        if(cur->child[i] != nullptr)
            return false;
    }
    return true;
}

void trie::del(string &key)
{
    this->root = del(key, this->root, 0);
    return ;
}
node *trie::del(string &key, node *cur, int idx)
{
    // idx代表當前位於key的哪個位置 idx==1時表示cur在key[0] idx==0時cur在root
    if(cur == nullptr)
        return nullptr;
    
    //當前節點位於要刪除之字串的最後一個字元
    if(idx == key.size())
    {
        if(cur->EndOfWord == true)
            cur->EndOfWord = false;
        
        //若該節點為葉節點 則將之刪除
        if(no_child(cur) == true)
        {
            delete cur;
            cur = nullptr;
        }
        return cur;
    }

    cur->child[key[idx] - 'a'] = del(key, cur->child[key[idx] - 'a'], idx+1);

    //將子樹刪除後，檢查該節點是否有子節點以及是否為另一個字的結尾
    //若皆為非，則將之刪除
    if(cur->EndOfWord == false && no_child(cur) == true)
    {
        delete cur;
        cur = nullptr;
    }
    return cur;
}
