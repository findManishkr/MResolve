#include <iostream>
using namespace std;
// inplace bottum up solution

int minimumTotal(vector<vector<int>>& triangle) {
    int M = triangle.size();

   for( int i = M - 2; i >= 0; i--){
       for( int j = triangle[i].size()-1; j >= 0; j--){
           triangle[i][j] = triangle[i][j] + min( triangle[i+1][j], triangle[i+1][j+1]);
       }
   }

   return triangle[0][0];
}
// top down solution

class Solution {
    public:
         int inf = INT_MAX;
         int M , N; 
          vector < vector <int >> dp;
        int f( int i, int j, vector<vector<int>>& triangle ){
             // base case
             if( i >= M ) return 0 ;
    
             if( dp[i][j] != inf) return dp[i][j];  // ie (i,j)th state is already computed
    
             return dp[i][j] = triangle[i][j] + min( f(i+1,j,triangle), f(i+1, j+1,triangle)) ;     // else compute (i,j) th state
        }
        int minimumTotal(vector<vector<int>>& triangle) {
              M = triangle.size();
     ;
                dp.assign(M+1, vector<int>(M+1, inf));
              return f( 0, 0, triangle);
        }
    };

int main(){
    
    return 0;
}