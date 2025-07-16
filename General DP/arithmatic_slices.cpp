#include <iostream>
using namespace std;
class Solution {
    public:
         // top down apporach
         int N ;
         vector<int>dp;
         int f( vector <int>&a, int i){
                if( i <= 1) return dp[i] = 0;
                if( dp[i] != -1) return dp[i];
                 
                  return dp[i] =  (a[i] - a[i-1]) == (a[i-1] -a[i-2]) ? f(a, i-1) + 1 : 0;
         }
             
         
         
        int numberOfArithmeticSlices(vector<int>& nums) {
                 N = nums.size();
                   dp.assign(N+5, -1);
                 int sum = 0;
               
                 for( int i = 0; i < N; i++)
                    sum +=  f(nums, i);
                    return sum;
        }
    };
            /*
    
           recuurence relation
               f(i) =    f(i-1) + 1 , if( a[i]- a[i-1] == a[i-1] - a[i-2]) else f(i) == 0
    
    
    
    
            */
                      // bottom up approach

            class Solution {
                public:
                    int bottomUp ( vector<int>&a){
                          int N = a.size();
                              int sum = 0;
                               vector<int >dp(N+1, 0);
                          for( int i = 0; i < N; i++){
                                   for( int j = 2; j < N; j++){
                                      if( a[j] - a[j-1] == a[j-1]- a[j-2])
                                        dp[j] = dp[j-1] + 1;
                                   }
                                   sum += dp[i];
                          }
                          return sum;
                    }
                    int numberOfArithmeticSlices(vector<int>& nums) {
                        
                        return bottomUp( nums);
                    }
                };
int main(){
    return 0;
}