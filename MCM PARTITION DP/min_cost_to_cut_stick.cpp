/*
https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

*/


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define pb push_back
#define inf INT_MAX

// top down 
class Solution {
public:
    int dp[105][105];
     vector <int> cut;
     int f( int i, int j){
          // base case 
          if( i + 1 == j) return 0;
           if( dp[i][j] != -1) return dp[i][j];
          int ans = inf;
          for( int k = i+1; k < j; k++)
            ans = min( ans, f(i,k)+ f(k,j) + (cut[j]- cut[i]));

            return dp[i][j] = ans;
     }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
           cut.clear();
            cut.pb(0);
            for( int i = 0; i < cuts.size(); i++)
             cut.pb( cuts[i]);
            cut.pb(n);
              memset(dp, -1 ,sizeof(dp));
            return f(0, cut.size() -1 );
    }
};
int main(){
    
    return 0;
}