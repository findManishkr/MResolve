/*
https://www.geeksforgeeks.org/problems/geeks-training/0


*/

#include <iostream>
using namespace std;

// bottom up solution
int maximumPoints(vector<vector<int>>& arr) {
    int N = arr.size();
vector< vector<int>>dp(N, vector<int>(3));
    // base case 
     dp[N-1][0] = arr[N-1][0];
       dp[N-1][1] = arr[N-1][1];
         dp[N-1][2] = arr[N-1][2];
         
     for( int i = N-2; i >= 0; i--){
         
         dp[i][0] = arr[i][0] + max(dp[i+1][1], dp[i+1][2]);
           dp[i][1] = arr[i][1] + max(dp[i+1][0], dp[i+1][2]);
             dp[i][2] = arr[i][2] + max(dp[i+1][0], dp[i+1][1]);
         
     }     
    int ans = max( {dp[0][0], dp[0][1], dp[0][2]});
    return ans;
}
int main(){

    
    return 0;
}