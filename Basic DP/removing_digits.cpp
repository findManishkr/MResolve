

#include <bits/stdc++.h>
using namespace std;

 vector<int>memo;
int maxDigit( int n){
      if( n <= 0) return 0;
    return max( n%10, maxDigit(n/10) );
}
int f( int n){
     if( n == 0) return 0;
     if( n >= 1 && n <= 9) return 1;
       if(memo[n] != -1) return memo[n];  // nth state is alreday computed 
                                         //   else calculate nth state
    return memo[n] = 1 + f(n - maxDigit(n) );
} 
   
int bottomUp( int n){

     vector<int>dp(n+1);
      
        while( n > 0){

        }

}
int main(){    
   int n;
   cin >> n;
     memo.clear();
     memo.resize(n+5,-1);

 cout << f(n) << endl;
     
        
    return 0;
}