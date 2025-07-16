/*

https://leetcode.com/problems/longest-palindromic-subsequence/description/

*/

#include <iostream>
using namespace std;
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
class Solution {
    public:
        int M;
        int dp[1005][1005];
        int f( string &s, int i, int j){
              if( i == j) return 1;
              if( i > j) return 0;
              
               if( dp[i][j] != -1) return dp[i][j];
                
               return  dp[i][j] = (s[i] == s[j] ? 2 + f(s,i+1,j-1) :   max( f(s,i+1,j),f(s,i,j-1) ) );
        }
        int longestPalindromeSubseq(string s) {
             M = s.size();
              memset(dp, -1, sizeof(dp) );
             return f(s,0,M-1);
        }
    };
int main(){ setupIO();


    return 0;
}