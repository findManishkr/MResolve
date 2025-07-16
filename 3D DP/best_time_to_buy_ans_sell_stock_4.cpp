/*


https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

*/


#include <iostream>
#include <vector>
#include <cstring> // memset
using namespace std;
class Solution {
    public:
        vector <int>p;
        int N ;
         int dp[1005][105][2];
        /*
           f(_,_,_) returns max profit , after doing atmost k transcition from ith day to n-1 th day
        */
        int f( int idx, int k, bool on){
            // base case
              if( idx == N || k <= 0 ) return 0;
    
               if(dp[idx][k][on] != -1) return dp[idx][k][on];  // (idx,k,on) state is already computed, else compute that state
           
              int a = f( idx + 1, k, on);
                int b  = 0 ;
                if( on == 1 ){
                     b =  p[idx] + f( idx+1, k -1, 0) ;
                }else if( on == 0 && k > 0){
                   b =      f(idx+1, k, 1 ) -p[idx]  ;
                }
              return dp[idx][k][on] =  max(a,b);
        }
        int maxProfit(int k, vector<int>& prices) {
             // brute force
                N = prices.size();
                p = prices;
              
            // Initialize DP table with -1
           
            memset(dp, -1, sizeof(dp));
    
             return f(0,k,0);
        }
    };
    class Solution {
        public:
              int N;
              int dp[1005][105][2];
             int f( vector<int>&prices, int idx, int k , int on){
                 if( idx == N ||  k <= 0 ) return 0;
        
                    if(dp[idx][k][on] != -1) return dp[idx][k][on];
                // int ans = ninf;
                 // avoid the idx th stock (wheter selling or buying)
               int ans = f(prices, idx+1, k, on );
        
                 if( on ){
                     ans = max(ans,  prices[idx] + f(prices,idx+1,k-1,false));
                 }else{
                     if( k > 0){
                        ans = max(ans, f(prices, idx+1, k, true) - prices[idx]);
                     }
                 }
                 return dp[idx][k][on] = ans;
             }
            int maxProfit(int k, vector<int>& prices) {
                N = prices.size();
        
                 memset(dp, -1, sizeof(dp));
                return f(prices,0,k,0);
            }
        };
int main(){
    
    Solution ob;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << "Maximum Profit: " << ob.maxProfit(k, prices) << endl;
    return 0;
}