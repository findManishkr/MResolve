
#include <iostream>
#include <vector>
using namespace std;
int mod = 1e9 + 7;


#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif
 
 vector<int>dp;
int f( int x,  vector<int>&c){
    // base case
     if( x == 0) return 1;
     if(x < 0) return 0;
     
      if( dp[x] != -1) return dp[x];
 
     int ans = 0;
     for( int i = 0; i < c.size(); i++){
        if( x - c[i]  >= 0)
        ans = ( ans   + f(x - c[i] ,c) ) % mod;
     }
      
   return  dp[x] =  ans ;
}

// int fbu( int x, vector<int>&c){

//       int n = c.size();

//        vector<int>dp(x+1, 0);

//          dp[0] = 1;

//           for( int i = 1; i <= x; i++){
//               for( int j = 0; j <n; j++){
//                    if( i - c[j] >= 0)
//                    dp[i] = ( dp[i] + dp[i - c[j]]) % mod;
//               }
             
//           }

//           return dp[x];
// }



int main(){ SETUP_IO
     int n , x;
      cin >> n >> x;

      vector<int>c(n);
      for( int i  = 0; i < n;i++)
       cin >> c[i];
      
      dp.assign(n+1,-1);
      cout << f( x, c) << endl;
    return 0;
}



