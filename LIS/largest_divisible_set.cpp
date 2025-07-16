/*

https://leetcode.com/problems/largest-divisible-subset/

*/


/*

https://leetcode.com/problems/largest-divisible-subset/solutions/6620153/dp-sorting-with-images-example-walkthrough-c-python-java/

    read this article as well
*/

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
                  /*
                    reccurence relation
                      f(i) :  returns the length of largest subset ending at i
                     f(i) =  1 + max( f(j) ) for all j belog {0,to i -1};
                     and max value of f(i) over all i belong (0 to N - 1) gives the length of largest subset

                     then i backtracked to find soution


                  */




             int N = nums.size();
             sort( nums.begin(),nums.end());
             vector <int> dp(N,1);      // initially every number is subset of itself
             vector < int > parent(N, -1);

             for( int i = 0; i < N; i++){

                  for( int j = 0; j < i; j++){
                     if( !(nums[i] % nums[j]) &&  dp[i] < 1 + dp[j] ){
                            parent[i] = j;
                            dp[i] = 1 + dp[j];
                     }
                  }
             }

              // now back track to construct solution ie subset;

            // find index of the max length subset

            int maxLen = 0, lastIdx = -1;

            for( int i = 0; i < N; i++){
                  if( dp[i] > maxLen){
                      maxLen = dp[i];
                      lastIdx = i;
                  }
            }

            vector <int> subset;

            for( int i = lastIdx; i != -1; i = parent[i]){
                  subset.push_back( nums[i]);
            }
           
           reverse( subset.begin(),subset.end());

           return subset;
    }
};
int main(){
    return 0;
}
