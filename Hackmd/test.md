# 題解

<!-- markdownlint-disable MD003 MD022 MD033 -->

## 動態規劃

### 最長回文子字串 *(Longest Palindromic Substring)*

### 最長回文子序列 *(Longest Palindromic Subsequence)*

> Given a sequence s, find the length of the longest palindromic subsequence in it

* 令$dp_{i,j}$為$s[i\dotsb j]$中最長回文子序列長度
* $dp_{i,j}=\begin{cases}
&max(dp_{i+1, j}, dp_{i, j-1}) &,if\ \ s[i]\not=s[j]\\
&dp_{i+1, j-1} + 2 &,if\ \ s[i]=s[j]
\end{cases}$
* 狀態轉移來源來自左邊、下面、左下方，故須由左上往右下填
| dp | 0 | 1 | 2 | 3 |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 1 |  |  |  |
| 1 | X | 1 |  |  |
| 2 | X | X | 1 |  |
| 3 | X | X | X | 1 |

<details>
<summary>Code</summary>

```cpp=
vector<vector<int>> dp(len, vector<int>(len, 1));
int ans = INT_MIN;
for(int k = 1; k < len; k++)
{
    for(int i = 0; k + i < len; i++)
    {
        int j = k + i;
        if(j - i == 1)
        {
            if(str[i] == str[j])
                dp[i][j] = 2;
            else
                dp[i][j] = 1;
        }
        else
        {
            if(str[i] == str[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
        ans = max(ans, dp[i][j]);
    }
}
```

</details>

### 有限背包

## 二分搜尋

## Two Pointers

### [Codeforces 1265B](https://codeforces.com/contest/1265/problem/B)

* 所有在$[1,m]$中的數，包含在一個長度為$m$的區間
  $\Rightarrow$所有已選數字中位置最右$rb$與最左$lb$
  $\Rightarrow rb - lb = m - 1$
* 從數字小到大遍歷每個數，並同時記錄 $lb,\ rb$
* $pos[i]$紀錄$i+1$的$index$

<details>
<summary>Code</summary>

```cpp=
l = r = pos[0];
for(int i = 1; i < len; i++)
{
    if(pos[i] < l)
        l = pos[i];
    else if(pos[i] > r)
        r = pos[i];
    
    if(r - l == i)
        cout << 1;
    else
        cout << 0;
}
cout << endl;
```

</details>

### tags: `Competitive Programming`
