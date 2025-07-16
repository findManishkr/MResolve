/*
lc_70


*/


/*

  //top down solution : (recursion + memoization)


 int f( int n, vector<int>&dp){
   

         if( n <= 3) return n;

         if( dp[n-1] != -1)
         return dp[n-1];

        dp[n-1] = f(n-1,dp) + f(n-2,dp);

         return dp[n-1];
   }
    int climbStairs(int n) {
   
       // time : O(N) 
       // space : O(N) + O(N) ( vector space, recursive call stack)
    


        vector<int>dp(n,-1);

        return f(n,dp);
    }


      // bottom up solution
    int climbStairs(int n) {
          if( n <= 3) return n;
         vector<int>dp(n+1);
         
           dp[2] = 2;
           dp[3] = 3;
           for( int i = 4; i <= n ;i++){
              dp[i] = dp[i-1] + dp[i-2];
           }
            
            return dp[n];
    }

    /*

    