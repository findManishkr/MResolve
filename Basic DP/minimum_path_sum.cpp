/*
https://leetcode.com/problems/minimum-path-sum/description/

*/

#include <iostream>
using namespace std;

// top down solution
class Solution {
    public:
         int inf = INT_MAX;
         int M, N;
         vector< vector<int>>dp;
         int f( int i , int j , vector<vector<int>>& grid ){
               // base case
               if( i == M-1 && j == N-1) return grid[M-1][N-1];
              
              if( dp[i][j] != -1) return dp[i][j];    // ie (i,j)th state is already computed
               
               if( i >= M || j >= N ) return inf;
            
            return  dp[i][j] = grid[i][j] + min( f(i+1,j,grid), f(i,j+1,grid));  // else comput (i,j)th state
         }
        int minPathSum(vector<vector<int>>& grid) {
              M = grid.size();
              N = grid[0].size();
               dp.assign( M+1, vector<int>(N+1,-1));
              return f(0,0,grid);
        }
    };
// bottom up solution

class Solution {
    public:
        int M, N;
        int inf = INT_MAX;
        int minPathSum(vector<vector<int>>& grid) {
               M =  grid.size();
               N = grid[0].size();
                vector< vector<int>>dp( M, vector<int>(N,0));
                 
                 // base case 
    
                 dp[0][0] = grid[0][0];
                      for( int i = 1;  i < M; i++)
                        dp[i][0] = grid[i][0] + dp[i-1][0];
                        for( int j = 1; j < N; j++)
                            dp[0][j] = grid[0][j] + dp[0][j-1];
                        
                    for( int i = 1; i < M; i++){
                         for( int j = 1; j < N; j++){
                          
                              dp[i][j] = grid[i][j] + min ( dp[i-1][j] ,  dp[i][j-1]);
                         }
                    }
               return dp[M-1][N-1];
        }
    };
    //   again a bottom solution 
    class Solution {
        public:
            int M, N;
            int inf = INT_MAX;
            int minPathSum(vector<vector<int>>& grid) {
                   M =  grid.size();
                   N = grid[0].size();
                    vector< vector<int>>dp( M, vector<int>(N,0));
                     
                     // base case 
                           dp[0][0] = grid[0][0];
                            
                        for( int i = 0; i < M; i++){
                             for( int j = 0; j < N; j++){
                                 if( i == 0 && j == 0) continue;
                                  dp[i][j] = grid[i][j] + min ( i-1 >= 0 ? dp[i-1][j] : inf, j-1 >= 0 ? dp[i][j-1] : inf);
                             }
                        }
                   return dp[M-1][N-1];
            }
        };
int main(){
    return 0;
}