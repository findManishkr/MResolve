/*
https://leetcode.com/problems/unique-paths/description/
lc_62


*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;




/*

ll nCr(ll n, ll r) {
    // time : O(r)
      //  space : O(1)
    if (r > n) return 0; 
    r = min(r, n - r);   

    ll res = 1;

    for (ll i = 1; i <= r; i++) {
        res = (res * (n - i + 1)) / i;
    }

    return res;
}

*/
/*
 // top - down solution

int nCr( int n, int r, vector< vector<int>>&dp){
    if( r == 0 || r == n) return 1;
    if( r == 1 ) return n;
    if( dp[n][r] != -1) return dp[n][r] ;

    return dp[n][r] = nCr(n-1,r,dp) + nCr(n-1,r-1,dp);
}
int uniquePaths(int m, int n) {
    
     int N = m + n - 2;
     int R = min(m-1,n-1);
     vector< vector<int>>dp(N+1,vector<int>(R+1,-1)) ;

   int ans = nCr(N,R,dp);

   return ans;
}

*/

/*

int nCr( int n, int r){

  vector< vector<int>>dp(n+1, vector<int>(r+1,0));
     //dp[i][j] -> gives no of unique paths to reach i , j from 0,-
    for( int i = 0; i <= n; i++){
       for( int j = 0; j <= r; j++){
          if( i >= j){
              if((i >0 && j== 0) || j == i)
               dp[i][j] = 1;
              else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
          }
       }
    }
    return dp[n][r];
}
int uniquePaths(int m, int n) {
   
   return nCr(m+n-2,min(m-1,n-1));
}

*/

int main(){
          int n = 7, r = 3;
  
  vector< vector<int>>dp(n+1, vector<int>(r+1,0));
     //dp[i][j] -> gives no of unique paths to reach i , j from 0,-
    for( int i = 0; i <= n; i++){
       for( int j = 0; j <= r; j++){
          if( i >= j){
              if((i >0 && j== 0) || j == i)
               dp[i][j] = 1;
              else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
          }
       }
    }

         for(int i = 0; i <= dp.size(); i++){
           for( int j = 0; j <= dp[0].size(); j++){
              cout << dp[i][j]<<" ";
           }
           cout << endl;
         }

    return 0;
}