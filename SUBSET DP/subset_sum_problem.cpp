/*

http://geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


*/





#include <iostream>
using namespace std;

class Solution {
    public:
            int dp[205][10005];
       bool f( vector<int>&arr, int idx, int sum ){
           
           
            if( sum == 0) return true;
             if( idx >= arr.size() && sum > 0  ) return false;
             
             
                if(dp[idx][sum] != -1) return dp[idx][sum];
               
            // two choices pick or not pick
            // if not picked
            bool notPick = f(arr, idx+1, sum);
            // if picked
            bool Pick =   arr[idx] <= sum ? f(arr, idx+1, sum - arr[idx]) : f(arr,idx+1,sum);
            
            return   dp[idx][sum] = (notPick || Pick);
       }
      bool isSubsetSum(vector<int>& arr, int sum) {
            memset(dp, -1, sizeof(dp));
          return f(arr, 0, sum);
      }
  };
int main(){

    return 0;
}