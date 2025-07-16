/*
problem statement;
 Given a no 'N' . you can perform some  following operations any no of times
 1: subtract 1 from N;
 2: divide N by 2(if divisible);
 3: divide N by 3 ( if divisible)

 tell the no of minimum steps to reduce N to 1

*/


#include <iostream>
#include <vector>
#include <climits>

#define inf INT16_MAX
using namespace std;

// top-down solution
int f( int n , vector<int>&dp) {                       // f(i) ->returns min no of operation to reduce i to 1;
     if( n == 1) return 0;
     if( n == 2 || n == 3) return 1;

        if(dp[n] != -1) return dp[n];     // already pre -computed
        /// else compute first 
      
     return dp[n] = 1 + min( f(n-1,dp) , min( n % 2 == 0 ? f(n/2,dp) : inf, n % 3 == 0 ? f(n/3,dp) : inf  ) );   // compute
}
     

     // write bottom up solution
 int bottumUp( int n){
         if( n == 1) return 0;
         if( n == 2 || n == 3) return 1;
     vector<int>dp(n+1);
       dp[1] = 0, dp[2] = 1, dp[3] = 1;

       for( int i = 4 ; i <= n; i++)
          dp[i] = 1 + min( dp[i-1], min( i % 2 == 0 ? dp[i/2] : inf , i % 3== 0 ? dp[i/3]: inf));
       

   return dp[n];
 } 
int main(){
     int n  = 20;
     vector<int>dp;
     dp.clear();
     dp.resize(n+1,-1);

   cout <<  f(n,dp);
   cout << bottumUp(20);
    return 0;
}