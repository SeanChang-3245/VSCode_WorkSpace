#include <bits/stdc++.h>
#include "header/RMQ.h"

using namespace std;

#define endl '\n'


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    vector<int> vec{7,4,7,8,6,3,2,1,9,5,7};

    minSegment seg(vec);

    int len = vec.size();
    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            printf("[%d, %d] = %d\n", i, j, seg.rangequery(i, j));
        }
        cout << endl;
    }

    cout << endl;

    //seg.lvltravel();


    return 0;



}