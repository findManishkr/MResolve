/*
https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

*/


#include <iostream>
using namespace std;
// bottom up solution

class Solution {
      public:
      #define ninf INT_MIN
        int longestCommonSubstr(string& s1, string& s2) {
              int M = s1.size();
              int N = s2.size();
              vector < vector < int >>dp(M+2, vector <int>(N+2,0));
           
             int ans = 0;
              for( int i = 1; i <= M; i++ ){
                   for( int j = 1; j <= N; j++){
                       
                        if( s1[i-1] == s2[j-1]){
                            
                            
                         dp[i][j] = 1+ dp[i-1][j-1];
                          ans = max(ans, dp[i][j]);
                        }
                        else{
                            dp[i][j] = 0;
                        } 
                   }
              }
              return ans ;
        }
    };
   
    
 // solve by top down apporach also   
int main(){

    return 0;
}