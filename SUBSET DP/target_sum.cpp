/*
https://leetcode.com/problems/target-sum/description/

*/

#include <iostream>
using namespace std;
class Solution {
    public:
         int offset = 1000;
          int dp[21][2005];
        int f( vector<int>&nums, int idx, int sum , int target){
              // base case 
              if( idx >= nums.size())
              return sum == target ? 1 : 0;
                  if( dp[idx][sum + offset] != -1) return dp[idx][sum +offset];
              return dp[idx][sum + offset] = f(nums, idx+1, sum + nums[idx], target) +  f(nums, idx+1, sum - nums[idx], target);
        }
        int findTargetSumWays(vector<int>& nums, int target) {
                 memset(dp, -1, sizeof(dp));
            return f(nums, 0 ,0, target);
        }
    };
int main(){
    
    return 0;
}