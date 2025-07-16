/*
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

lc_1155

*/


#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int N = 1e6 + 5;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif

//--------------top- down solution ////////////////
class Solution {
    public:
    int Mod = 1e9+7;
     vector< vector<int>> dp;
    
      int f( int n, int k , int t){
         // base case 
          if(  n == 0 && t == 0) return 1; 
          if (n < 0   || t < 0) return 0;
    
           if(dp[n][t] != -1) return dp[n][t];
          int sum = 0;
           for( int j =1 ; j <= k; j++){
                if( (t - j) >= 0)
               sum  = ( sum + f(n-1,k, t-j) ) % Mod;
           } 
            
            return  dp[n][t] = sum;
      }

        int numRollsToTarget(int n, int k, int target) {
             dp.clear();
             dp.resize(n+1, vector<int>(target+1,-1));
            return f(n,k,target);
        }
    };

    //-------------------bottom up solution------------------------------
int main(){ SETUP_IO
    
     

      
    return 0;
}