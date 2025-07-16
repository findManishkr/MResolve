#include <iostream>
#include <vector>
using namespace std;
vector< vector<int>> ans; // ultimate answer

vector< vector<int>> f( vector<int>&coins, int x){
       // base case
       


}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n , x;
  cin >> n >> x;

  vector<int > coin(n);
  for( int i =0;i < n;i++) cin >> coin[i];

  vector< vector<int>> ans = f(coins,x);

   for( int i = 0; i < ans.size();i++){
    for( int j = 0; j < ans[0].size();j++){
          cout << ans[i][j] <<' ';
    }
    cout << '\n';
   }
    return 0;
}