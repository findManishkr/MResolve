

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e18

void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}


    vector<int> getLIS(vector<int>& arr) {
        int N = arr.size();
        
        
           vector < int> dp(N,1);
            vector < int > lis;
            vector <int>parent(N, -1);
          for( int i = 0; i < N; i++){
                for( int j = i -1; j >= 0; j--){
                      if( arr[j] < arr[i]  && dp[i] < dp[j] + 1  ){
                              dp[i] = 1 + dp[j];
                              parent[i] = j;
                      }
                }
          }
            
            // now find the index of last elment of lis
            
              int lastIdx = -1; int maxLen = 0;
                for( int i = 0;  i < N; i++){
                      if( dp[i] > maxLen){
                            maxLen = dp[i];
                            lastIdx = i;
                      }
                    
                }
                
        // now reconstruct the lis using parent array
        
         for( int i = lastIdx; i != -1 ; i = parent[i]){
                  lis.push_back( arr[i] );
         }
            reverse(lis.begin(),lis.end());
            
            for( int i  = 0; i < N; i++){
                  cout << i << " " << parent[i] <<'\n';
            }

        return lis;
    }


int main() {  setupIO();
    vector <int> arr =  //{ 10 ,9, 6, 8, 3, 5, 2, 9, 4, 10}   ;                     // {10, 22, 9, 33, 21, 50, 41, 60, 8};    
          {10, 9, 2, 5, 3, 7, 101, 18};

     vector <int>lis = getLIS(arr);

     for( int el : lis)
      cout << el << ' ';

    return 0;
}
