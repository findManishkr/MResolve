/*
https://leetcode.com/problems/unique-paths-ii/description/

*/

#include <iostream>
using namespace std;
// top down solution
class Solution {
    public:
       int M , N;
        vector< vector<int>>dp;
        int f( int i, int j,vector<vector<int>>&grid){
    
                if( (i == M-1 && j == N -1) && grid[i][j] != 1 ) return 1;
                else if((i == M-1 && j == N -1) && grid[i][j] ==1 ) return 0;
    
                if(i >= M || j >= N || grid[i][j] == 1 ) return 0;
                
                // if (i,j)th state is computed
                 if(dp[i][j] != -1) return dp[i][j];
                // else compute (i,j) th state
           return dp[i][j] =  f(i,j+1,grid) + f( i+1,j,grid);
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
               /*
                time complexity : O(M*N)
                auxiliary space complexity : O( max( M,N)) // max recursive depth
    
    
               */
    
    
              M = obstacleGrid.size();
              N = obstacleGrid[0].size();
                 dp.clear();
                 dp.resize(M+5, vector<int>(N+5,-1));
              return f(0,0,obstacleGrid);
        }
    };
int main(){

    return 0;
}