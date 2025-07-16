
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 1e18

#define S second
#define F first
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
 const ll Mod = 1e9+7;
int fbu( vector<int>&nums ){
     
    
     int N = nums.size();
      vector <int >dp(N+1, 1);     // initialized with 1
      int ans = 1;
      for( int i = 0; i < N; i++){
          for( int j = 0; j < i; j++){
                 if( nums[i] > nums[j])
                 dp[i] = max( dp[i], 1 + dp[j]);
          }
          ans = max( ans, dp[i]);
      }
   return ans;

}
int main(){   setupIO();
         int N = 8;
       vector <int> length(N, 0);
        int ans = 1;
 vector <int>arr = {6, 2, 5, 1, 7, 4 ,8,3};
   for( int i = 0; i < arr.size(); i++){
        length[i] = 1;
        for( int j = 0; j < i ; j++){
             if( arr[j] < arr[i]){
                 length[i] = max(length[i], length[j]+ 1);
             }
        }
      ans = max( ans, length[i]);  
   }

          for( int el : length)
           cout << el <<' ';
           cout <<'\n'<< ans;
           
    return 0;
}

