#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int N = 1e6 + 5;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif
vector<int>memo(N,-1);
int f( int n ){
     // base case 
      if( n == 0 ) return 1;

         if( memo[n] != -1) return memo[n];
         
          int sum = 0;

       for( int i = 1; i <= min(n,6) ;i++){
       
         sum = (sum  % mod + f(n -i) % mod) % mod;
       }

      return memo[n] =  sum ;
       
}

int bottomUp( int n){
       if( n == 0) return 1 ;

      vector<int>dp(n+1);
        dp[0] = 1;
         for( int i = 1; i <= n; i++){

                  int sum = 0 ;
              for( int j = 1; j <= min(i,6); j++)
                   sum =  (sum  % mod +   dp[i-j] %mod ) % mod;        
              
              dp[i] = sum;

         }

         

  return dp[n];
}
int fbu( int n ){
       vector<int>dp(n+1,0);
         if( n == 0) return 1;

         dp[0] = 1;
          for(int i = 1; i <= n; i++){
             for( int j = 1; j <= min(i ,6) ; j++)
               dp[i] +=  dp[i] + dp[i-j];
          }

          return dp[n];
}
int main(){ SETUP_IO
    int n ;
    cin >> n;

    cout << f(n) <<'\n';
      //cout << bottomUp(n) <<'\n';

      
    return 0;
}