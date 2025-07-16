/*
https://leetcode.com/problems/unique-binary-search-trees/

*/


#include <iostream>
using namespace std;
// top down 
class Solution {
public:
     int dp[25];
     int f( int n){
         // base case 
           if( n <= 1) return 1;
            if( dp[n] != -1) return dp[n];
           int sum = 0;
            for( int i = 1; i <= n; i++)
             sum += f( i -1) * f( n - i);

             return dp[n] =  sum;
     }
    int numTrees(int n) {
          memset(dp, -1, sizeof(dp));
        return f(n);
    }
};

bottom up

int main(){
    return 0;
}