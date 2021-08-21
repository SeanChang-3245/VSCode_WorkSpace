#include <bits/stdc++.h>
using namespace std;

class ac
{
private:
    int cnt = 0;
    vector<vector<int>> tr; // 儲存trie
    vector<bool> endofword; // 儲存節點是否為一個pattern的結束
    vector<int> fail;       // 儲存每個節點的fail pointer指向哪個節點
    void insert(string str);
    void build();           // 替每個節點建立fail pointer

public:
    ac(vector<string>& pat)
    {
        tr.reserve(10000);
        endofword.reserve(10000);
        fail.reserve(10000);
        for(int i = 0; i < 10000; i++)
        {
            tr[i] = vector<int>(26, 0);
            endofword[i] = false;
            fail[i] = 0;
        }

        for(string str : pat)
            insert(str);
        
        build();

    }

    int query(string& txt);

};

void ac::insert(string str)
{
    int cur = 0;
    int idx = 0;

    while(idx < str.size())
    {
        int c = str[idx++] - 'a';
        if(tr[cur][c] == 0)
        {
            tr[cur][c] = ++cnt;
        }
        cur = tr[cur][c];
    }
    endofword[cur] = true;
}

void ac::build()
{
    int cur = 0;
    queue<int> bfs;
    for(int i = 0; i < 26; i++)
    {
        if(tr[cur][i] != 0)              //tr[cur][i] 代表cur的子節點i 在tr中的位置 即為tr[tr[cur][i]]
            bfs.push(tr[cur][i]);
    }

    while(bfs.size())
    {
        cur = bfs.front();  // cur為父節點 此處是求子節點的fail pointer  因root與第一層的節點之fail pointer皆為root
        bfs.pop();

        for(int i = 0; i < 26; i++)
        {
            if(tr[cur][i] != 0)
                fail[tr[cur][i]] = tr[fail[cur]][i] ,bfs.push(tr[cur][i]);
            else
                tr[cur][i] = tr[fail[cur]][i];  //當子節點不存在時，將其指向其父節點之fail pointer再加上字母 i+'a'  (見下圖                   
        }
        
    }
}
/*
原理: 如果 tr[fail[cur]][i] 存在，則cur的i子節點指向 tr[fail[cur]][i] 
      否則 指向 tr[fail[fail[cur]]][i] 並持續迭代

假設此時 cur 在 ba ，並要建立 bat 的 fail pointer
其應要指向 tr[fail[cur]][i] 即 at
但 at 不存在
故在原始方法中，要指向 tr[fail[fail[cur]]][i] 即 t (fail[cur] == a   fail[fail[cur]] == root)
但若在建立 a 的子節點之 fail pointer 時
將 at 指向 a 的 fail pointer 再加上 t  
即指向 at 的 fail pointer
與原始方法的目的相同 

         root
        / | \
        b a  t
        | |
        a c
        |
        t
*/


int ac::query(string& txt)
{
    int cur = 0;
    int cnt = 0;
    int len = txt.size();

    for(int i = 0; i < len; i++)
    {
        cur = tr[cur][txt[i] - 'a'];
        for(int j = cur;  j != 0 && endofword[j] == true; j = fail[j])
        {
            cnt++;
            endofword[j] = false;
        }
    }
    return cnt;
}


/*
cur = :
1.當 狀態cur + 字母txt[i]-'a' 存在------ cur = 狀態cur + 字母txt[i]-'a'        (Trie本身性質)
2.當 狀態cur + 字母txt[i]-'a' 不存在---- cur = fail[狀態cur + 字母txt[i]-'a']  (由上 build() else 中的程式所決定)
*/