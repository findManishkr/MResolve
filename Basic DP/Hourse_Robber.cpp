#include <iostream>
#include <vector>
using namespace std;

/*

int f( vector<int>&nums, int i, vector<int>&dp){   //  
    //'f' returns maximum amount of money by looting houses from index i to n-1 such that 2 adjacent houses are looted
    // /
    //    time : O(N)
    //    space : O(N) due to recursive stack:
    // 
    
    // base case 
    if(i >= nums.size())
          return  0; 
    
        if( dp[i] != -1) return dp[i];

       int a = nums[i] + f( nums, i+ 2,dp);
       int b =  f(nums, i+ 1,dp);


    return dp[i] =  max(a,b);
}
int rob(vector<int>& nums) {
    int n = nums.size();
     vector<int>dp(n+1,-1);

    int ans =  f(nums,0,dp);

    
    return ans;
}

*/

int rob(vector<int>& nums) {
    /*
      bottom-up solution
      
     time : O(N)
     space : O(N)
    */

    int N = nums.size();
     vector<int>dp( N );
      dp[N-1] = nums[N-1];
      if( N > 1)
      dp[N-2] = max(nums[N-1], nums[N-2]);

      for( int i = N-3; i >= 0;i--){
         dp[i] = max( nums[i]+ dp[i+2], dp[i+1] );
      }

   return dp[0];
}
int main(){
    return 0;
}