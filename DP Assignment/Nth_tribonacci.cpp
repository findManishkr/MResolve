/*
https://leetcode.com/problems/n-th-tribonacci-number/

lc_1137

*/

/*-----------bottom up */

class Solution {
    public:
        int tribonacci(int n) {
             if( n == 0) return 0;
             if( n ==1 || n == 2) return 1;
             vector<int>dp(n+1);
             dp[0] = 0, dp[1] = 1, dp[2] = 1;
              for(int i = 3; i <= n ;i++)
               dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    
               return dp[n];
        }
    };

 /*---------------top- down */   


 class Solution {
    public:
      vector<int>dp;
       int T( int n){
          if( n == 0) return 0;
          if( n == 1 || n == 2) return 1;
           if( dp[n] != -1) return dp[n];
          return dp[n] =  T(n-1)+ T(n-2)+ T(n-3);
       }
        int tribonacci(int n) {
             dp.clear();
             dp.resize(n+1,-1);
            return T(n);
        }
    };