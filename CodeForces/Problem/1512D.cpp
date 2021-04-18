#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin >> t;
    for(int x = 0; x < t; x++)
    {
        long long len;
        long long total = 0;
        cin >> len;


        vector<int> vec(len+2);
        for(int i = 0; i < len+2; i++)
        {
            cin >> vec[i];
            total += vec[i];
        }

        sort(vec.begin(), vec.end());

        auto it1 = find(vec.begin(), vec.end(), total - 2*(vec[len+1]));
        auto it2 = find(vec.begin(), vec.end(), total - 2*(vec[len]));

        if(it1 == vec.end() || it1 == vec.begin()+len+1)
        {
            if(it2 == vec.end() || it2 == vec.begin()+len)
            {
                cout << -1 << endl;
                continue;
            }
            else
            {
                *(vec.begin()+len) = -1;
                *(it2) = -1;   
            }
        }
        else
        {
            *(vec.begin()+len+1) = -1;
            *(it1) = -1;
        }

        for(long long i : vec)
        {
            if(i != -1)
                cout << i << ' ';
        }
            
        cout << endl;

    }
    return 0;

}