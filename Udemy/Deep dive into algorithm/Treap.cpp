#include "Treap.hpp"
#include <windows.h>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));

    /*
    treap t;

    t.root = new node(1,1, nullptr, new node(2,2, nullptr,nullptr));
    t.root = t.l_rotate(t.root);
*/

    vector<int> v;

    for(int i = 0; i < 4096; i++)
    {
        v.push_back(i);
    }
    //random_shuffle(v.begin(), v.end());
    treap tree(v);

    //tree.inorder();

    cout << tree.height() << endl;

    Sleep(1000);

    return 0;


}