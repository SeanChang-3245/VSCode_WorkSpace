#include <bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=BXCEFAzhxGY
//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string tar, pat;
    cin >> tar >> pat;

    int tlen = tar.size(); // 要比對的字串的長度
    int plen = pat.size(); // pattern 的長度
    vector<int> lps(plen, 0); // 儲存最長相同前綴後綴的陣列
    // lps[0] 必為0

    // 計算lps
    {
        int i = 0; // 表示當前比對到前綴的哪個位置
        int j = 1; // 表示當前要計算哪個位置的lps

        while (j < plen && i < plen)
        {
            if (pat[i] == pat[j])
            {
                lps[j] = i + 1;
                i++;
                j++;
            }
            else // pat[i] != pat[j]
            {
                if (i == 0) // 若此時pat[j]根pat[0]比對，若兩者不同，則lps[j]必為0
                {
                    lps[j] = 0;
                    i = 0;
                    j++;
                }
                else   // 表此時pat[j]不是在與pat[0]比對，pat[j]可能接著pat[j-1], pat[j-2]...
                {      // 並與pat[0], pat[1], pat[2] 相匹配
                    //在pat[i]時沒匹配，但在pat[i-1]時有匹配
                    //既然pat[j-1]和pat[i-1]相匹配，pat[j-2]和pat[i-2]相匹配...
                    //再利用lps，pat[j-1] 會和 pat[lps[i-1]-1] 匹配
                    //即可接續前面，繼續比對pat[j]
                    i = lps[i - 1];
                }
            }
        }
    }

    int i = 0;
    int j = 0;

    while (i < tlen)
    {
        if (pat[j] == tar[i])
        {
            i++;
            j++;

            if (j == plen) // 若匹配完成，則輸出pattern在tar中的哪裡出現
            {
                cout << i - j << ' ';
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
                j = lps[j - 1]; //j移到pat[0]~pat[j]中，與其後綴相同的前綴的下一個字元
                                //tar[i]可能會與上述字元相匹配，故沒有i++
            else  //若tar[i]與pat[0]不匹配，則tar[i]不可能與pat[0]的前綴相匹配
                i++;  //故i++
        }
    }

    return 0;
}