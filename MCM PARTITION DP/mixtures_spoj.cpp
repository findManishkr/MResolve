/*

https://www.spoj.com/problems/MIXTURES/

*/


#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
int dp[105][105];
int g( vector<int>&colors, int i, int j){
      int res = 0;
      for( int l = i; l <=j; l++)
        res  = (res + colors[l]) % 100;
        return res;
}
int f( int i, int j, vector <int>&arr){
       // base case 
         if( i == j) return 0;
          if( dp[i][j] != -1) return dp[i][j];
       int ans = inf;
       for( int k = i; k < j; k++){
         ans = min( ans, f(i,k,arr) + f(k+1,j,arr) + g(arr,i,k) * g(arr,k+1,j));
       }
    return  dp[i][j] = ans;
}


int main(){ setupIO();

        int n;
     while( cin >> n){

         vector<int>colors;
         for( int i = 0; i < n;i++){
              int x;
              cin >> x;
            colors.push_back(x); 
         }
             memset(dp,-1,sizeof(dp));
         cout << f(0, colors.size()-1,colors) <<'\n';
      
     }   

    return 0;
}