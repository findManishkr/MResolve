/*
https://leetcode.com/problems/minimum-falling-path-sum-ii/

*/

#include <iostream>
#include <vector>
using namespace std;

// top down solution
class Solution {
    public:
    #define inf INT_MAX
        int M, N;
    
        vector< vector <int>>dp;
        int f( int i, int j,vector<vector<int>>& grid ){
             
            // base case
            if( i == M -1) return grid[M-1][j];
    
            if( dp[i][j] != inf) return dp[i][j];    // ie (i,j)th state is already computed
                int minimum = (M == 1 && N == 1 )? 0 : inf;
                for( int k = 0; k < N; k++){
                     if( k == j ) continue;
                     minimum = min( minimum, f(i+1,k,grid) ) ;
                }
            return  dp[i][j] =  grid[i][j] + minimum;  //   else compute (i,j)th state
    
        }
        int minFallingPathSum(vector<vector<int>>& grid) {
              
              M = grid.size();
              N = grid[0].size(); 
                dp.clear();
                dp.resize(M+1, vector<int>(N+1, inf ));
              
               int mini = inf;
               for( int j = 0;j < N; j++){
                  mini = min( mini, f(0,j,grid));
               }
          return mini;
        }
    };

    // also write its bottom up solution
int main(){
    return 0;
}