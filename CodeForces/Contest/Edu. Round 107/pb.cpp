#include <iostream>
#include <cmath>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int p = 0 ; p < t; p++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int gcd=1;
        int k = pow(10,c-1);
        while(1)
        {
            if(gcd < k)
                gcd*=2;
            else
                break;
        }

       // cout << "test1: " << k << endl;

        int x = gcd, y = gcd;

        k = pow(10, a-1);
        while(x < k)
            x*=3;

        k = pow(10, b-1);
        while(y < k)
            y *= 5;



        cout << x << ' ' << y << endl;


    }

}
