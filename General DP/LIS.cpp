/*
https://leetcode.com/problems/longest-increasing-subsequence/description/

https://leetcode.com/problems/longest-increasing-subsequence/submissions/1605598011/
*/

#include <iostream>
using namespace std;
#define inf INT_MAX
class Solution {
public:
      vector<int>dp;
    int f( vector <int>&nums, int i){          // top down 
          
          if( i == 0 ) return dp[0] =  1;

            if( dp[i] != -1) return dp[i];
           int ans = -inf;
           for( int j = 0; j < i; j++){
               if( nums[i] > nums[j])
              ans =  max(ans, 1 + f(nums,j) );
           }
                if( ans == -inf) return 1;
           return  dp[i] = ans ;
    }
    int bottomUp( vector <int >&ans){
        
            /// bottom up approach

          int N = nums.size();
           vector <int >dp(N+1, 1);     // initialized with 1
           int ans = 1;
           for( int i = 0; i < N; i++){
               for( int j = 0; j < i; j++){
                      if( nums[i] > nums[j])
                      dp[i] = max( dp[i], 1 + dp[j]);
               }
               ans = max( ans, dp[i]);
           }
        return ans;

          
    }
    int lengthOfLIS(vector<int>& nums) {
           int N = nums.size();
            dp.assign( N+5, -1);
            int ans = 1;

              for( int i = 0; i < N; i++)
              ans  =     max(ans, f(nums, i));
              return ans;
          
             return bottomUp( nums );
    }
};

int main(){
    return 0;
}