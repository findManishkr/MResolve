/*

https://atcoder.jp/contests/dp/tasks/dp_c

*/


 //   bottom -um solution


#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif
int N = 1e5 + 5;


int main(){ SETUP_IO
     
    int n;
    cin >> n;

    vector< vector<int>> dp(n, vector<int>(3));
     int a, b, c;
     cin >> a >> b >> c;
      // 'a' the activity is zero
       dp[0][0] = a;
        dp[0][1] = b;
        dp[0][2] = c;
        
       for( int i = 1; i <n; i++){
           cin >> a >> b >> c ;
           dp[i][0] = a  + max( dp[i-1][1], dp[i-1][2]);
           dp[i][1] = b + max( dp[i-1][0], dp[i-1][2]);
           dp[i][2] = c  + max( dp[i-1][0], dp[i-1][1]);
       }  

        int ans = max( dp[n-1][0], max( dp[n-1][1],dp[n-1][2]) );

         cout << ans << endl;
     
    return 0;
}