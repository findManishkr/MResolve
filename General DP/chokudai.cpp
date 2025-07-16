

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 1e18

#define S second
#define F first
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
 const ll Mod = 1e9+7;
// int dp[100005][9];

//  int f(  string &s , string &t,  int i, int j){
//                /* 
//                  time :  O( N);
             
               
//                */

//             if( j >= t.size() ) return 1;
//             if( i >= s.size()) return 0;

//             if( dp[i][j] != -1) return dp[i][j];
          
               
//           return  dp[i][j] =  ( s[i] == t[j] ? f(s,t,i+1,j+1) + f(s,t, i+1,j) : f(s,t,i+1,j) ) % Mod;
// }
int fbu( string s, string t){
           int N = s.size();
           int M = t.size();
        vector < vector <int>>dp( N+1, vector<int>(M,0));
       
       
           

    // Base case: an empty 't' is a subsequence of any suffix of 's'
          for (int i = 0; i <= N; i++) 
               dp[i][M] = 1;
    
        for( int i = N -1; i >= 0; i--){
             for( int j = M -1; j >= 0; j--){
               if( s[i] == t[j])
                 dp[i][j] =  (dp[ i+1][j+1] + dp[i+1][j]) % Mod;
               else
                   dp[i][j] = dp[i+1][j] % Mod;      
             } 
        }
        return dp[0][0];
}
int main(){ setupIO();
  string s;
  cin >> s;
  string t = "chokudai";
//   memset(dp, -1, sizeof(dp));
//   cout << f(s,t,0,0) <<'\n';

cout << fbu(s,t) <<'\n';

    return 0;
}