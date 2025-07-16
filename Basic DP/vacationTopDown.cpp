
#include <bits/stdc++.h>
using namespace std;



#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif
int bottomUp( vector< vector<int>>&happ,int n){
    
    vector< vector<int>>dp(n, vector<int>(3));

    // base case :
     dp[n-1][0] = happ[n-1][0];
     dp[n-1][1]= happ[n-1][1];
     dp[n-1][2] = happ[n-1][2];

     for( int i  = n -2 ; i >= 0; i--){
         dp[i][0]  = happ[i][0] + max( dp[i+1][1], dp[i+1][2]);
         dp[i][1]  = happ[i][1] + max( dp[i+1][0], dp[i+1][2]);
         dp[i][2]  = happ[i][2] + max( dp[i+1][0], dp[i+1][1]);
     }
     
     
   int ans = max( dp[0][0], max( dp[0][1], dp[0][2]) );
      
     return ans;
}


int main(){ SETUP_IO
     
    int n;
    cin >> n;

    vector< vector<int>> happ(n, vector<int>(3));

       for( int i = 0; i < n; i++)
         cin >> happ[i][0] >> happ[i][1] >> happ[i][2];
       
       
         /*
       // dp table to track max happiness ending with each activity

        vector< vector<int >>dp(n, vector<int>(3,0));

         
         
       // base case :  first day
        dp[0][0] = happ[0][0];
        dp[0][1] = happ[0][1];
        dp[0][2] = happ[0][2];

        for( int i = 1; i < n; i++){
              dp[i][0] = happ[i][0] + max( dp[i-1][1], dp[i-1][2]);
              dp[i][1] = happ[i][1] + max( dp[i-1][0], dp[i-1][2]);
              dp[i][2] = happ[i][2] + max( dp[i-1][0], dp[i-1][1]);
        }
   
         int result = max(  dp[n-1][0], max( dp[n-1][1] , dp[n-1][2] ));

         */


           cout << bottomUp(happ,n) << endl;

    return 0;
}