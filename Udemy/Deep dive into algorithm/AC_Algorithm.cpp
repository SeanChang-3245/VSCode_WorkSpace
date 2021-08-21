#include "AC_Algorithm.hpp"

//https://oi-wiki.org/string/ac-automaton/#_3
//



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    vector<string> v;

   for(int i = 0; i < m; i++)
   {
       string tmp;
       cin >> tmp;
       v.push_back(tmp);
       
   }
    
    string txt;
    cin >> txt;
    ac k(v);
    cout << k.query(txt);


}