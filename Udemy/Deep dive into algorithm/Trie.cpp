#include "Trie.hpp"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    trie t;
    t.insert("a");
    t.insert("aa");
    t.insert("abc");
    t.insert("aac");
    t.insert("aab");
    t.insert("aba");
    t.insert("aca");

    cout << t.search("a") << ' ';
    cout << t.search("aa") << ' ';
    cout << t.search("abc") << ' ';
    cout << t.search("aac") << ' ';
    cout << t.search("aab") << ' ';
    cout << t.search("aba") << ' ';
    cout << t.search("aca") << ' ';
   
    string str;
    cin >> str;
    t.del(str);

    cout << endl;
    cout << t.search("a") << ' ';
    cout << t.search("aa") << ' ';
    cout << t.search("abc") << ' ';
    cout << t.search("aac") << ' ';
    cout << t.search("aab") << ' ';
    cout << t.search("aba") << ' ';
    cout << t.search("aca") << ' ';

    t.insert("abcd");

    cout << endl;
    cout << t.search("a") << ' ';
    cout << t.search("aa") << ' ';
    cout << t.search("abc") << ' ';
    cout << t.search("aac") << ' ';
    cout << t.search("aab") << ' ';
    cout << t.search("aba") << ' ';
    cout << t.search("aca") << ' ';
    cout << t.search("ccc") << ' ';
    cout << t.search("abcd") << ' ';


}