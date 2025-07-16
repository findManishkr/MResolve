/*
https://leetcode.com/problems/minimum-falling-path-sum/

*/

#include <iostream>
#include <vector>
using namespace std;
// top down solution

class Solution {
    public:
        int inf = INT_MAX ;
        int M;
         vector < vector <int >> dp;
    
        int f( int i , int j,vector<vector<int>>& matrix ){
             // base case
             if( i == M-1 && (j >= 0 && j < M) ) return matrix[i][j];
              
           
    
            if( j < 0 || j >= M) return inf;
            if( dp[i][j] != inf) return dp[i][j]; // ie (i,j)the state is already computed
                int bottomleft =   f(i+1,j-1,matrix);
                int bottomMiddle = f( i+1, j,matrix);
                int bottomRight = f( i+1, j+1,matrix);
              return  dp[i][j] =  matrix[i][j] + min( bottomleft, min(bottomMiddle, bottomRight) );    // else compute (i,j)th state
        }
        int minFallingPathSum(vector<vector<int>>& matrix) {
             M = matrix.size();
                 dp.clear();
                 dp.resize(M+1, vector<int>(M+1,inf));
              
              int minimum = inf;
              for( int j = 0; j < M; j++)
                 minimum = min( minimum, f(0,j, matrix) );
              
           return minimum;
        }
    };

    // inplace bottom up solution
    int minFallingPathSum(vector<vector<int>>& matrix) {
        /*
         time complxity : o(M^2);
         space complexity : O(1);
        */
  
           int M = matrix.size();
  
           // in place modification
             for( int i = 1; i < M; i++){
               for( int j = 0; j < M; j++){
                   matrix[i][j] = matrix[i][j] + min(  (j -1 < 0 ? inf : matrix[i-1][j-1] ), min( matrix[i-1][j], (j + 1 >= M ? inf : matrix[i-1][j+1] )) );
               }
             }
         return *min_element( matrix[M-1].begin(),matrix[M-1].end());
      }
int main(){
    return 0;
}