#include <iostream>
#include <vector>
#include <math.h>


using namespace std;



int main()
{
    int m;
    std::cin >> m;
    vector<int> vec(m, 9);
    for(int i= 0; i < m; i++)
    {
        std::cout << i+1 << ' ';
    }
    return 0;
}