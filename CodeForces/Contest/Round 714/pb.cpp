#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;


bool cmp(int l, int r)
{
    if(l == r)
        return l < r;
    return l ==r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> vec;

    vec.push_back(1);
    vec.push_back(1);vec.push_back(1);

    do
    {
        for(int i : vec)
            cout << i << ' ';
    }while(next_permutation(vec.begin(), vec.end()), cmp);


}
