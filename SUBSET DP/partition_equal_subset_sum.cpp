#include <iostream>
using namespace std;
/*

// approach 1;
  converte 3d dp into 2d dp

*/
int f(vector<int>&arr,int idx, int subset1, int subset2){
    // base case

if( idx >= arr.size())
  return  subset1 == subset2;

// if not picked 
//   bool notPick = f( arr, idx+1, subset1, subset2);
// if picked 
return f(arr, idx+1, subset1 + arr[idx], subset2) || f(arr, idx+1, subset1 , subset2+ arr[idx]) ;



//  return  notPick || Pick;
}
bool canPartition(vector<int>& nums) {

return f(nums,0,0,0);
}
class Solution {
    public:
        int offset = 20000;        // offset becuase parameter x can be negative
         int dp[205][40005];
        bool f( vector<int>&nums, int idx, int x){                    // x = subsetSum1 - subSetSum2
                  
             if( idx >= nums.size()) return x == 0;     // base case
    
             if( dp[idx][x + offset] != -1) return dp[idx][x+offset];
    
             return  dp[idx][x+offset] = f(nums, idx+1, x + nums[idx] ) || f(nums, idx + 1, x - nums[idx]);
    
        }
        bool canPartition(vector<int>& nums) {
              memset(dp, -1, sizeof(dp));
            return f( nums,0, 0);
        }
    };
int main(){
    return 0;
}