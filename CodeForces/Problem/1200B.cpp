#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;
    while(t--)
    {
        int n, bag, k;
        bool valid = true;
        cin >> n >> bag >> k;

        vector<int> h(n);
        for(int& i : h)
            cin >> i;
        
        for(int i = 0; i < n-1; i++)
        {
            if(h[i] + k >= h[i+1])
            {
                bag += min(h[i], k + h[i] - h[i+1]);
            }
            else
            {
                bag -= h[i+1] - k - h[i]; 
            }

            if(bag < 0)
            {
                valid = false;
                break;
            }
        }

        if(bag < 0 || valid == false)
            cout << "no" << endl;
        else
            cout << "yes" << endl;

    }
    return 0;
}