/*
https://atcoder.jp/contests/dp/tasks/dp_f

*/


#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif

string longestCommonSubsequence(string text1, string text2) {
    int M = text1.size();
    int N = text2.size();

  vector< vector < int >>dp(M+1, vector<int>(N+1,0) );
    for( int i = M -1; i >= 0; i--){
        for( int j = N -1 ; j >= 0; j--){
           
             if( text1[i] == text2[j])
              dp[i][j] = 1 + dp[i+1][j+1];
              else {
                 dp[i][j] = max( dp[i+1][j] , dp[i][j+1]);
              }
        }
    }

       int i = 0;
       int j = 0;
       string lcs = "";
       while( i < M && j < N){
           if( text1[i] == text2[j]){
              lcs.push_back(text1[i]);
              i++;
              j++;
           }else if( dp[i+1][j] >= dp[i][j+1])
                     i++;
             else j++;
                  
       }

             
        return lcs;
} 

int main() {  SETUP_IO;
string s, t;
cin >> s >> t;
  
cout << longestCommonSubsequence(s,t) << '\n';
    return 0;
}
