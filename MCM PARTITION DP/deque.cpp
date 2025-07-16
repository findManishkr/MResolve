#include <bits/stdc++.h>
using namespace std;
#define ll long long

void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
int arr[3005];
 ll dpp[3005][3005];
ll f( int i, int j){
         // base case 
         if( i == j) return arr[j];

           if( dpp[i][j] != -1 ) return dpp[i][j];

         return  dpp[i][j] = max( arr[i] - f( i+1, j) , arr[j] - f( i, j -1));
}
ll fbu( int N ){
       ll dp[N][N];
      memset(dp,0, sizeof(dp));
              
      // base case ,ie for single element
        for( int i = 0;i < N; i++) dp[i][i] = arr[i];
           
      for( int len = 2; len <= N; len++){
          for( int i = 0; i < (N - len + 1); i++){
              int j = i + len -1;
              dp[i][j] = max( arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
          }
      }


return dp[0][N-1];
}
int main(){ setupIO();

      int N;
      cin >> N;

      for( int i = 0; i < N; i++) cin >> arr[i];
       
    //   memset( dp, -1 , sizeof(dp) );

    //   cout << f(0, N -1) << endl;
      
    cout << fbu(N) << endl;
 
    return 0;
}
