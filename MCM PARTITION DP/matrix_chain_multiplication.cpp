/*

https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

*/


#include <bits/stdc++.h>
using namespace std;
#include < vector>
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
// top down approach 
#define inf INT_MAX
typedef long long ll;
class Solution {
  public:
     vector < vector <int>>dp;
     ll f( int i , int j, vector<int>&arr){     // return the least no of multiplication from idx i to j
           if( i == j || j -1 == i) return 0;
            
              if( dp[i][j] != -1 ) return dp[i][j];    // ie (i,j)th state is already computed , else compute 
            ll ans = inf;
            for( int k = i + 1; k <= j-1 ; k++)
             ans = min(ans, ( f(i,k,arr)+ f(k,j,arr) + arr[i]*arr[j]*arr[k] ));
             
             return dp[i][j] = ans;
           
     }
    int matrixMultiplication(vector<int> &arr) {
        int N = arr.size();
         dp.clear();
         dp.resize(N+5, vector<int>(N+5, -1));      // ans would always be +ve int
        return f(0, N-1, arr);
    }
};

// bottom up approach

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
         int N = arr.size();
          vector < vector <int>>tab(N,vector<int>(N,0));
          // as if arr len ie 1 or 2 , tab[] = 0
            
            for( int len = 3; len <= N; len++){
                   
                for( int i = 0; i + len - 1 < N; i++){
                     int j = i + len - 1;
                     tab[i][j] = INT_MAX;
                     for( int k = i + 1; k < j ; k++)
                      tab[i][j] = min( tab[i][j] , tab[i][k] + tab[k][j] + arr[i]* arr[k] * arr[j]);
                }
            }
            return tab[0][N-1];
    }
};
int main(){ setupIO();
   

    return 0;
}